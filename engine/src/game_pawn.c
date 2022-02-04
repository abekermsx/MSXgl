// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │   ▄▄▄           
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │  ██   ▄▀██ ▄█▄█ ▄███
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │  ▀█▄█ ▀▄██ ██ █ ▀█▄▄
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘  
//  by Guillaume 'Aoineko' Blanchard under CC-BY-AS license
//─────────────────────────────────────────────────────────────────────────────
// Game pawn module
//─────────────────────────────────────────────────────────────────────────────
#include "game_pawn.h"
#include "vdp.h"
#include "memory.h"

//=============================================================================
// FUNCTIONS
//=============================================================================

//-----------------------------------------------------------------------------
// Initialize game pawn
void GamePawn_Initialize(Game_Pawn* pawn, const Game_Sprite* sprtList, u8 sprtNum, const Game_Action* actList)
{
	// Initialize pawn structure
	Mem_Set(0xFF, pawn, sizeof(Game_Pawn));
	pawn->SpriteList = sprtList;
	pawn->SpriteNum = sprtNum;
	pawn->ActionList = actList;

	// Initialize pawn action
	GamePawn_SetAction(pawn, 0);
	
	// Initialize pawn sprite color
	loop(i, pawn->SpriteNum)
	{
		const Game_Sprite* sprt = &pawn->SpriteList[i];
		VDP_SetSpriteColorSM1(sprt->SpriteID, sprt->Color);
	}

}

//-----------------------------------------------------------------------------
// Set game pawn position
void GamePawn_SetPosition(Game_Pawn* pawn, u8 x, u8 y)
{
	pawn->PositionX = x;
	pawn->PositionY = y;
	pawn->TargetX = x;
	pawn->TargetY = y;
	pawn->Update |= PAWN_UPDATE_POSITION;
}


//-----------------------------------------------------------------------------
// Set game pawn action id
void GamePawn_SetAction(Game_Pawn* pawn, u8 id)
{
	if(pawn->ActionId != id)
	{
		pawn->ActionId = id;
		pawn->AnimTimer = 0;
		pawn->AnimStep = 0;
		pawn->Update |= PAWN_UPDATE_PATTERN;
	}
}

//-----------------------------------------------------------------------------
// Update animation of the game pawn
void GamePawn_Update(Game_Pawn* pawn)
{
	const Game_Action* act = &pawn->ActionList[pawn->ActionId];

	// Finished current animation step
	if(pawn->AnimTimer >= act->FrameList[pawn->AnimStep].Duration)
	{
		pawn->AnimTimer = 0;
		pawn->AnimStep++;
		pawn->Update |= PAWN_UPDATE_PATTERN;
	}

	// Finished last animation step
	if(pawn->AnimStep >= act->FrameNum)
	{
		if(act->Loop) // restart action
		{
			pawn->AnimTimer = 0;
			pawn->AnimStep = 0;
			pawn->Update |= PAWN_UPDATE_PATTERN;
		}
		else // stop action and transit to default action
		{
			GamePawn_SetAction(pawn, 0);
			return;
		}
	}
	
	// Execute event
	const Game_Frame* frame = &act->FrameList[pawn->AnimStep];
	if(frame->Event != 0)
		frame->Event();
	
	// Update animation
	pawn->AnimFrame = frame->Id;
	pawn->AnimTimer++;
	pawn->Counter++;

#if (GAMEPAWN_USE_PHYSICS)
	if(pawn->TargetY > pawn->PositionY) // Go down
	{
		u8 cellX = (pawn->TargetX + (pawn->BoundX / 2)) / 8;
		u8 cellY = (pawn->TargetY + pawn->BoundY) / 8;		
		u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (cellY * 32) + cellX);
		if(pawn->CollisionCB(tile))
		{
			pawn->PhysicsCB(PAWN_PHYSICS_COL_DOWN);
			pawn->TargetY = (cellY * 8) - pawn->BoundY;
		}
	}
	else if(pawn->TargetY < pawn->PositionY) // Go up
	{
		u8 cellX = (pawn->TargetX + (pawn->BoundX / 2)) / 8;
		u8 cellY = (pawn->TargetY) / 8;		
		u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (cellY * 32) + cellX);
		if(pawn->CollisionCB(tile))
		{
			pawn->PhysicsCB(PAWN_PHYSICS_COL_UP);
			pawn->TargetY = (cellY * 8) + 8;
		}
	}
	else // if(pawn->TargetY == pawn->PositionY)
	{
		u8 cellX = (pawn->TargetX + (pawn->BoundX / 2)) / 8;
		u8 cellY = (pawn->TargetY + pawn->BoundY) / 8;		
		u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (cellY * 32) + cellX);
		if(!pawn->CollisionCB(tile))
		{
			pawn->PhysicsCB(PAWN_PHYSICS_FALL);
		}
	}

	if(pawn->TargetX > pawn->PositionX) // Go right
	{
		u8 cellX = (pawn->TargetX + pawn->BoundX) / 8;
		u8 cellY = (pawn->TargetY + (pawn->BoundY / 2)) / 8;		
		u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (cellY * 32) + cellX);
		if(pawn->CollisionCB(tile))
		{
			pawn->PhysicsCB(PAWN_PHYSICS_COL_RIGHT);
			pawn->TargetX = (cellX * 8) - pawn->BoundX;
		}
	}
	else if(pawn->TargetX < pawn->PositionX) // Go left
	{
		u8 cellX = (pawn->TargetX) / 8;
		u8 cellY = (pawn->TargetY + (pawn->BoundY / 2)) / 8;		
		u8 tile = VDP_Peek_16K(g_ScreenLayoutLow + (cellY * 32) + cellX);
		if(pawn->CollisionCB(tile))
		{
			pawn->PhysicsCB(PAWN_PHYSICS_COL_LEFT);
			pawn->TargetX = (cellX * 8) + 8;
		}
	}

	pawn->PositionX = pawn->TargetX;
	pawn->PositionY = pawn->TargetY;
	pawn->Update |= PAWN_UPDATE_POSITION;
#endif
}

//-----------------------------------------------------------------------------
// Update rendering of the game pawn
void GamePawn_Draw(Game_Pawn* pawn)
{
	if(pawn->Update == 0)
		return;

	loop(i, pawn->SpriteNum)
	{
		const Game_Sprite* sprt = &pawn->SpriteList[i];
		
		if(sprt->Flag & PAWN_SPRITE_EVEN)
		{
			if((pawn->Counter & 1) != 0)
				continue;
		}
		else if(sprt->Flag & PAWN_SPRITE_ODD)
		{
			if((pawn->Counter & 1) == 0)
				continue;
		}

		if(pawn->Update & PAWN_UPDATE_POSITION)
		{
			u8 x = pawn->PositionX + sprt->OffsetX;
			u8 y = pawn->PositionY + sprt->OffsetY;	
			VDP_SetSpritePosition(sprt->SpriteID, x, y);
		}
		
		if(sprt->Flag || (pawn->Update & PAWN_UPDATE_PATTERN))
		{
			u8 pattern = (pawn->AnimFrame * sprt->DataMultiply) + sprt->DataOffset;
			VDP_SetSpritePattern(sprt->SpriteID, pattern);
		}
	}
	pawn->Update = 0;
}
