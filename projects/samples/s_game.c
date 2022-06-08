// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │   ▄▄▄                ▄▄      
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │  ▀█▄  ▄▀██ ▄█▄█ ██▀▄ ██  ▄███
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │  ▄▄█▀ ▀▄██ ██ █ ██▀  ▀█▄ ▀█▄▄
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘                 ▀▀
//  Game module sample
//─────────────────────────────────────────────────────────────────────────────

//=============================================================================
// INCLUDES
//=============================================================================
#include "msxgl.h"
#include "game.h"
#include "game_pawn.h"
#include "math.h"
#include "debug.h"

//=============================================================================
// DEFINES
//=============================================================================

#define FORCE		24
#define GRAVITY		1
#define GROUND		192

// Library's logo
#define MSX_GL "\x02\x03\x04\x05"

// Prototype
bool State_Initialize();
bool State_Game();
bool State_Pause();

//=============================================================================
// READ-ONLY DATA
//=============================================================================

// Fonts
#include "font\font_mgl_sample8.h"
// Sprites by GrafxKid (https://opengameart.org/content/super-random-sprites)
#include "content\data_sprt_layer.h"
#include "content\data_bg.h"
// Sinus & cosinus table
#include "mathtable\mt_trigo_64.inc"

// Character animation data
const c8 g_ChrAnim[] = { '|', '\\', '-', '/' };

// Pawn sprite layers
const Game_Sprite g_SpriteLayers[] =
{
	{ 0, 0, 0,  COLOR_BLACK, PAWN_SPRITE_EVEN },
	{ 0, 0, 12, COLOR_BLACK, PAWN_SPRITE_ODD },
	{ 0, 0, 4,  COLOR_WHITE, 0 },
	{ 0, 0, 8,  COLOR_LIGHT_RED, 0 },
};

// Idle animation frames
const Game_Frame g_FramesIdle[] =
{
	{ 6*16,	48,	null },
	{ 7*16,	24,	null },
};

// Move animation frames
const Game_Frame g_FramesMove[] =
{
	{ 0*16,	4,	null },
	{ 1*16,	4,	null },
	{ 2*16,	4,	null },
	{ 3*16,	4,	null },
	{ 4*16,	4,	null },
	{ 5*16,	4,	null },
};

// Jump animation frames
const Game_Frame g_FramesJump[] =
{
	{ 3*16,	4,	null },
	{ 8*16,	4,	null },
};

// Fall animation frames
const Game_Frame g_FramesFall[] =
{
	{ 9*16,	4,	null },
};

// Actions id
enum ANIM_ACTION_ID
{
	ACTION_IDLE = 0,
	ACTION_MOVE,
	ACTION_JUMP,
	ACTION_FALL,
};

// List of all player actions
const Game_Action g_AnimActions[] =
{ //  Frames        Number                  Loop? Interrupt?
	{ g_FramesIdle, numberof(g_FramesIdle), true, true },
	{ g_FramesMove, numberof(g_FramesMove), true, true },
	{ g_FramesJump, numberof(g_FramesJump), true, true },
	{ g_FramesFall, numberof(g_FramesFall), true, true },
};

//=============================================================================
// MEMORY DATA
//=============================================================================

Game_Pawn g_PlayerPawn;

bool g_bFlicker = true;
bool g_bMoving = false;
bool g_bJumping = false;
i8   g_VelocityY;
u8   g_PrevRow8 = 0xFF;
i8   g_DX = 0;
i8   g_DY = 0;
u8   g_LastEvent = 0;
u16  g_Level = 0;

//=============================================================================
// FUNCTIONS
//=============================================================================

// Physics callback
void PhysicsEvent(u8 event, u8 tile)
{
	switch(event)
	{
	case PAWN_PHYSICS_BORDER_DOWN:
	case PAWN_PHYSICS_BORDER_RIGHT:
		g_LastEvent = event;
		break;
	
	case PAWN_PHYSICS_COL_DOWN: // Handle downward collisions 
		g_bJumping = false;
		break;
	
	case PAWN_PHYSICS_COL_UP: // Handle upward collisions
		g_VelocityY = 0;
		break;
	
	case PAWN_PHYSICS_FALL: // Handle falling
		if(!g_bJumping)
		{
			g_bJumping = true;
			g_VelocityY = 0;
		}
		break;
	};
}

// Collision callback
bool PhysicsCollision(u8 tile)
{
	// return (tile < 8) || (tile >= 32);
	return (tile < 8);
	// return false;
}

//-----------------------------------------------------------------------------
//
void DrawLevel()
{
	Print_SetPosition(25, 0);
	Print_DrawInt(g_Level);

	// Background
	loop(i, 24-2)
		VDP_FillVRAM((i == 12) ? 9 : (i < 12) ? 16 : 8, g_ScreenLayoutLow + (i+2) * 32, 0, 32);
	// Ground
	Math_SetRandomSeed16(g_Level);
	loop(i, 8)
	{
		if(i == 7)
			Math_SetRandomSeed16(g_Level + 1);
		u8 y = Math_GetRandom16() & 0x07 ;
		loop(j, y)
		{
			VDP_FillVRAM((j == (y - 1)) ? 1 : 3, g_ScreenLayoutLow + ((23 - j) * 32) + (i * 4), 0, 4);
		}
	}
	// Plateforms
	loop(i, 12)
	{
		u8 rnd = Math_GetRandom16();
		VDP_FillVRAM(1, g_ScreenLayoutLow + ((rnd & 0x0F) + 2) * 32 + (rnd >> 3), 0, 2);
	}	
}


//-----------------------------------------------------------------------------
//
bool State_Initialize()
{
	// Initialize display
	VDP_EnableDisplay(false);
	VDP_SetColor(COLOR_BLACK);
	
	// Initialize pattern
	VDP_FillVRAM(0x00, g_ScreenPatternLow, 0, 256*8); // Clear pattern
	VDP_WriteVRAM(g_DataBackground, g_ScreenPatternLow, 0, 24*8);
	Print_SetTextFont(g_Font_MGL_Sample8, 32);
	Print_SetColor(0xF, 0x1);

	// Initialize color
	VDP_FillVRAM(0xF0, g_ScreenColorLow, 0, 32); // Clear color
	VDP_Poke_16K(0xF7, g_ScreenColorLow + 0);
	VDP_Poke_16K(0x54, g_ScreenColorLow + 1);
	VDP_Poke_16K(0xF5, g_ScreenColorLow + 2);
	VDP_Poke_16K(0x99, g_ScreenColorLow + 3);

	// Initialize sprite
	VDP_SetSpriteFlag(VDP_SPRITE_SIZE_16);
	VDP_LoadSpritePattern(g_DataSprtLayer, 0, 13*4*4);	
	VDP_SetSpriteSM1(3, 0, 208, 0, 0); // hide

	// Init player pawn
	GamePawn_Initialize(&g_PlayerPawn, g_SpriteLayers, numberof(g_SpriteLayers), 0, g_AnimActions);
	GamePawn_SetPosition(&g_PlayerPawn, 16, 16);
	GamePawn_InitializePhysics(&g_PlayerPawn, PhysicsEvent, PhysicsCollision, 16, 16);

	// Initialize text
	Print_SetPosition(0, 0);
	Print_DrawCharX(' ', 32);
	Print_SetPosition(0, 0);
	Print_DrawText(MSX_GL " GAME SAMPLE     Lvl");
	Print_DrawLineH(0, 1, 32);

	// Initialize layout
	DrawLevel();

	VDP_EnableDisplay(true);

	Game_SetState(State_Game);
	return false; // Frame finished
}

//-----------------------------------------------------------------------------
//
bool State_Game()
{
	// Update player animation & physics
	u8 act = ACTION_IDLE;
	if(g_bJumping && (g_VelocityY >= 0))
		act = ACTION_JUMP;
	else if(g_bJumping)
		act = ACTION_FALL;
	else if(g_bMoving)
		act = ACTION_MOVE;
	GamePawn_SetAction(&g_PlayerPawn, act);
	GamePawn_SetMovement(&g_PlayerPawn, g_DX, g_DY);
// VDP_SetColor(4);
	GamePawn_Update(&g_PlayerPawn);
// VDP_SetColor(8);
	GamePawn_Draw(&g_PlayerPawn);
// VDP_SetColor(1);

	// Character animation
	Print_SetPosition(31, 0);
	Print_DrawChar(g_ChrAnim[g_PlayerPawn.Counter & 0x03]);

	// Background horizon blink
	VDP_FillVRAM(g_PlayerPawn.Counter & 1 ? 9 : 10, g_ScreenLayoutLow + (12+2) * 32, 0, 32);

	// Handle collision events
	switch(g_LastEvent)
	{
	case PAWN_PHYSICS_BORDER_DOWN:
		/* handle game over */
		break;
	case PAWN_PHYSICS_BORDER_RIGHT:
		g_LastEvent = 0;
		GamePawn_SetPosition(&g_PlayerPawn, 0+4, g_PlayerPawn.PositionY);
		g_Level++;
		DrawLevel();
		break;
	}

	// Update movement
	g_DX = 0;
	g_DY = 0;
	u8 row8 = Keyboard_Read(8);
	if(IS_KEY_PRESSED(row8, KEY_RIGHT))
	{
		g_DX++;
		g_bMoving = true;
	}
	else if(IS_KEY_PRESSED(row8, KEY_LEFT))
	{
		g_DX--;
		g_bMoving = true;
	}
	else
		g_bMoving = false;
	
	if(g_bJumping)
	{
		g_DY -= g_VelocityY / 4;
		
		g_VelocityY -= GRAVITY;
		if(g_VelocityY < -FORCE)
			g_VelocityY = -FORCE;

	}
	else if(IS_KEY_PRESSED(row8, KEY_SPACE) || IS_KEY_PRESSED(row8, KEY_UP))
	{
		g_bJumping = true;
		g_VelocityY = FORCE;
	}

	if(IS_KEY_PRESSED(row8, KEY_HOME) && !IS_KEY_PRESSED(g_PrevRow8, KEY_HOME))
		g_bFlicker = 1 - g_bFlicker;
	
	g_PrevRow8 = row8;

	if(Keyboard_IsKeyPressed(KEY_ESC))
		Game_Exit();

		
	return true; // Frame finished
}

//-----------------------------------------------------------------------------
//
bool State_Pause()
{
	return true; // Frame finished
}

//=============================================================================
// MAIN LOOP
//=============================================================================

//-----------------------------------------------------------------------------
// Programme entry point
void main()
{
	Game_SetState(State_Initialize);
	Game_MainLoop(VDP_MODE_GRAPHIC1);
}