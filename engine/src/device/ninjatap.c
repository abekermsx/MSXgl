// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘
//  by Guillaume 'Aoineko' Blanchard under CC BY-SA license
//─────────────────────────────────────────────────────────────────────────────
// PCCM Ninja-Tap Driver v2.0 for MSX (Primary & C-lib routine)
// Copyright 1994 1995 Knight's Chamber, all rights reserved.
// 	Written by Firm Knight.
//─────────────────────────────────────────────────────────────────────────────
#include "ninjatap.h"

//=============================================================================
// DEFINES
//=============================================================================

//=============================================================================
// READ-ONLY DATA
//=============================================================================

// INCLUDE_ASM(NTap_Dummy, "ninjatap.asm");

void NTap_Dummy()
{
	__asm
		#include "ninjatap.asm"
	__endasm;
}

//=============================================================================
// MEMORY DATA
//=============================================================================

u8 g_NTap_Result[3];

//=============================================================================
// FUNCTIONS
//=============================================================================

// 
u8 NTap_Check()
{
	__asm
		call		CKNTAP
	__endasm;
	return g_NTap_Result[1];
}
