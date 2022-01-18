// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘
//  by Guillaume 'Aoineko' Blanchard under CC-BY-AS license
//─────────────────────────────────────────────────────────────────────────────
// VGM replayer
//  https://vgmrips.net/wiki/VGM_Specification
//─────────────────────────────────────────────────────────────────────────────
#include "vgm_player.h"
#include "bios_mainrom.h"

//=============================================================================
// DEFINES
//=============================================================================

#define VGM_IDENT *(u32*)"Vgm "

//=============================================================================
// MEMORY DATA
//=============================================================================

const struct VGM_Header* g_VGM_Header;
const u8* g_VGM_Pointer;
const u8* g_VGM_Loop;
u16       g_VGM_WaitCount;
u16       g_VGM_WaitFrame;
u8        g_VGM_State;

//=============================================================================
// FUNCTIONS
//=============================================================================

//-----------------------------------------------------------------------------
/// Play a VGM data
bool VGM_Play(const void* addr, bool loop)
{
	g_VGM_Header = (struct VGM_Header*)addr;

	if(g_VGM_Header->Ident != VGM_IDENT)
		return false;
	
	g_VGM_State = 0;
	if(loop)
		g_VGM_State |= VGM_STATE_LOOP;

	g_VGM_Pointer = (u8*)((u16)&g_VGM_Header->Data_offset + (u16)g_VGM_Header->Data_offset);
	if(g_VGM_Header->Loop_offset)
		g_VGM_Loop = (u8*)((u16)&g_VGM_Header->Loop_offset + (u16)g_VGM_Header->Loop_offset);
	else
		g_VGM_Loop = 0;
	g_VGM_WaitCount = 0;

	if(g_ROMVersion.VSF)
		VGM_SetFrequency50Hz();
	else
		VGM_SetFrequency60Hz();

	VGM_Resume();
	return true;
}

//-----------------------------------------------------------------------------
// Play a ayVGM data
void VGM_Stop()
{
	VGM_Pause();
	g_VGM_Pointer = (u8*)((u16)&g_VGM_Header->Data_offset + (u16)g_VGM_Header->Data_offset);
	g_VGM_WaitCount = 0;
}

//-----------------------------------------------------------------------------
/// Decode a frame of VGM data
void VGM_Decode()
{
	if(!(g_VGM_State & VGM_STATE_PLAY))
		return;
	
	while(g_VGM_WaitCount < g_VGM_WaitFrame)
	{
		if(*g_VGM_Pointer == 0xA0) // AY8910, write value dd to register aa
		{
			PSG_SetRegister(g_VGM_Pointer[1], g_VGM_Pointer[2]);
			g_VGM_Pointer += 2;
		}
		else if(*g_VGM_Pointer == 0x61) // Wait n samples, n can range from 0 to 65535 (approx 1.49 seconds). Longer pauses than this are represented by multiple wait commands.
		{
			g_VGM_WaitCount += *(u16*)(g_VGM_Pointer+1);
			g_VGM_Pointer += 2;
		}
		else if(*g_VGM_Pointer == 0x62) // Wait 735 samples (60th of a second), a shortcut for 0x61 0xdf 0x02
		{
			g_VGM_WaitCount += 735;
		}
		else if(*g_VGM_Pointer == 0x63) // Wait 882 samples (50th of a second), a shortcut for 0x61 0x72 0x03
		{
			g_VGM_WaitCount += 882;
		}
		else if(*g_VGM_Pointer == 0x66) // End of sound data
		{
			if((g_VGM_Loop != 0) && (g_VGM_State & VGM_STATE_LOOP))
			{
				g_VGM_Pointer = g_VGM_Loop;
			}
			else
			{
				PSG_Silent();
				return;
			}
		}
		else if ((*g_VGM_Pointer & 0xF0) == 0x70) // wait n+1 samples, n can range from 0 to 15.
		{
			g_VGM_WaitCount += 1 + *g_VGM_Pointer & 0x0F;
		}
		else
		{
		}
		g_VGM_Pointer++;
	}
	g_VGM_WaitCount -= g_VGM_WaitFrame;
}