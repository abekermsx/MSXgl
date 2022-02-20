// Autogenerated Arkos AKM player for MSX-GL library 
// On 20/02/2022 et 13:52:18, 14    
#include "akm_player.h" 
void AKM_Dummy()         
{                         
__asm                     
PLY_AKM_REGISTERS_OFFSETVOLUME = .+1
PLY_AKM_DATA_OFFSETTRANSPOSITION = .+1
PLY_AKM_STOP_SOUNDS = .+1
PLY_AKM_SOUNDEFFECTDATA_OFFSETINVERTEDVOLUME = .+2
PLY_AKM_DATA_OFFSETPTSTARTTRACK = .+2
PLY_AKM_START:
__endasm;
}

// Initialize SFX
void AKM_SFX_Init()
{
__asm
PLY_AKM_INITSOUNDEFFECTS:
PLY_AKM_DATA_OFFSETWAITEMPTYCELL:
PLY_AKM_OFFSET2B:
PLY_AKM_OFFSET1B:
PLY_AKM_USE_HOOKS:
	ld (PLY_AKM_PTSOUNDEFFECTTABLE), hl
PLY_AKM_SOUNDEFFECTDATA_OFFSETCURRENTSTEP:
	ret 
__endasm;
}

// Play SFX      
void AKM_SFX_Play()
{
__asm
PLY_AKM_PLAYSOUNDEFFECT:
PLY_AKM_SOUNDEFFECTDATA_OFFSETSPEED:
PLY_AKM_DATA_OFFSETPTTRACK:
	dec a
PLY_AKM_DATA_OFFSETBASENOTE = .+1
PLY_AKM_DATA_OFFSETESCAPENOTE = .+2
PLY_AKM_REGISTERS_OFFSETSOFTWAREPERIODLSB:
	ld hl, (PLY_AKM_PTSOUNDEFFECTTABLE)
PLY_AKM_DATA_OFFSETESCAPEINSTRUMENT:
	ld e, a
PLY_AKM_DATA_OFFSETPTINSTRUMENT = .+1
PLY_AKM_DATA_OFFSETESCAPEWAIT:
PLY_AKM_DATA_OFFSETSECONDARYINSTRUMENT:
PLY_AKM_REGISTERS_OFFSETSOFTWAREPERIODMSB:
	ld d, #0x0
    add hl, de
PLY_AKM_DATA_OFFSETINSTRUMENTCURRENTSTEP:
	add hl, de
PLY_AKM_DATA_OFFSETINSTRUMENTSPEED:
	ld e, (hl)
PLY_AKM_DATA_OFFSETTRACKINVERTEDVOLUME:
	inc hl
PLY_AKM_DATA_OFFSETISPITCHUPDOWNUSED:
	ld d, (hl)
PLY_AKM_DATA_OFFSETTRACKPITCHINTEGER:
	ld a, (de)
    inc de
PLY_AKM_DATA_OFFSETTRACKPITCHDECIMAL:
	ex af, af'
PLY_AKM_DATA_OFFSETTRACKPITCHSPEED:
	ld a, b
PLY_AKM_DATA_OFFSETISARPEGGIOTABLEUSED = .+1
PLY_AKM_DATA_OFFSETPTARPEGGIOTABLE = .+2
    ld hl, #PLY_AKM_CHANNEL1_SOUNDEFFECTDATA
PLY_AKM_DATA_OFFSETPTARPEGGIOOFFSET = .+1
    ld b, #0x0
PLY_AKM_DATA_OFFSETARPEGGIOCURRENTSPEED = .+1
PLY_AKM_DATA_OFFSETARPEGGIOCURRENTSTEP:
	sla c
PLY_AKM_DATA_OFFSETCURRENTARPEGGIOVALUE = .+1
PLY_AKM_DATA_OFFSETARPEGGIOORIGINALSPEED:
	sla c
PLY_AKM_DATA_OFFSETPTPITCHTABLE = .+1
PLY_AKM_DATA_OFFSETISPITCHTABLEUSED:
	sla c
    add hl, bc
PLY_AKM_DATA_OFFSETPTPITCHOFFSET:
	ld (hl), e
PLY_AKM_DATA_OFFSETPITCHCURRENTSTEP:
	inc hl
PLY_AKM_DATA_OFFSETPITCHCURRENTSPEED:
	ld (hl), d
PLY_AKM_DATA_OFFSETPITCHORIGINALSPEED:
	inc hl
PLY_AKM_DATA_OFFSETCURRENTPITCHTABLEVALUE:
	ld (hl), a
    inc hl
    ld (hl), #0x0
    inc hl
    ex af, af'
    ld (hl), a
    ret 
__endasm;
}

// Stop SFX      
void AKM_SFX_Stop()
{
__asm
PLY_AKM_STOPSOUNDEFFECTFROMCHANNEL:
	add a, a
    add a, a
    add a, a
    ld e, a
    ld d, #0x0
    ld hl, #PLY_AKM_CHANNEL1_SOUNDEFFECTDATA
    add hl, de
    ld (hl), d
    inc hl
    ld (hl), d
    ret 
PLY_AKM_PLAYSOUNDEFFECTSSTREAM:
	rla 
    rla 
    ld ix, #PLY_AKM_CHANNEL1_SOUNDEFFECTDATA
    ld iy, #PLY_AKM_TRACK1_REGISTERS
    ld c, a
    call PLY_AKM_PSES_PLAY
    ld ix, #PLY_AKM_CHANNEL2_SOUNDEFFECTDATA
    ld iy, #PLY_AKM_TRACK2_REGISTERS
    srl c
    call PLY_AKM_PSES_PLAY
    ld ix, #PLY_AKM_CHANNEL3_SOUNDEFFECTDATA
    ld iy, #PLY_AKM_TRACK3_REGISTERS
    scf
    rr c
    call PLY_AKM_PSES_PLAY
    ld a, c
    ld (PLY_AKM_MIXERREGISTER), a
    ret 
PLY_AKM_PSES_PLAY:
	ld l, +0(ix)
    ld h, +1(ix)
    ld a, l
    or h
    ret z
PLY_AKM_PSES_READFIRSTBYTE:
	ld a, (hl)
    inc hl
    ld b, a
    rra 
    jr c, PLY_AKM_PSES_SOFTWAREORSOFTWAREANDHARDWARE
    rra 
    jr c, PLY_AKM_PSES_HARDWAREONLY
    rra 
    jr c, PLY_AKM_PSES_S_ENDORLOOP
    call PLY_AKM_PSES_MANAGEVOLUMEFROMA_FILTER4BITS
    rl b
    call PLY_AKM_PSES_READNOISEIFNEEDEDANDOPENORCLOSENOISECHANNEL
    set 2, c
    jr PLY_AKM_PSES_SAVEPOINTERANDEXIT
PLY_AKM_PSES_S_ENDORLOOP:
	rra 
    jr c, PLY_AKM_PSES_S_LOOP
    xor a
    ld +0(ix), a
    ld +1(ix), a
    ret 
PLY_AKM_PSES_S_LOOP:
	ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    jr PLY_AKM_PSES_READFIRSTBYTE
PLY_AKM_PSES_SAVEPOINTERANDEXIT:
	ld a, +3(ix)
    cp +4(ix)
    jr c, PLY_AKM_PSES_NOTREACHED
    ld +3(ix), #0x0
    .db 0xdd
    .db 0x75
    .db 0x0
    .db 0xdd
    .db 0x74
    .db 0x1
    ret 
PLY_AKM_PSES_NOTREACHED:
	inc +3(ix)
    ret 
PLY_AKM_PSES_HARDWAREONLY:
	call PLY_AKM_PSES_SHARED_READRETRIGHARDWAREENVPERIODNOISE
    set 2, c
    jr PLY_AKM_PSES_SAVEPOINTERANDEXIT
PLY_AKM_PSES_SOFTWAREORSOFTWAREANDHARDWARE:
	rra 
    jr c, PLY_AKM_PSES_SOFTWAREANDHARDWARE
    call PLY_AKM_PSES_MANAGEVOLUMEFROMA_FILTER4BITS
    rl b
    call PLY_AKM_PSES_READNOISEIFNEEDEDANDOPENORCLOSENOISECHANNEL
    res 2, c
    call PLY_AKM_PSES_READSOFTWAREPERIOD
    jr PLY_AKM_PSES_SAVEPOINTERANDEXIT
PLY_AKM_PSES_SOFTWAREANDHARDWARE:
	call PLY_AKM_PSES_SHARED_READRETRIGHARDWAREENVPERIODNOISE
    call PLY_AKM_PSES_READSOFTWAREPERIOD
    res 2, c
    jr PLY_AKM_PSES_SAVEPOINTERANDEXIT
PLY_AKM_PSES_SHARED_READRETRIGHARDWAREENVPERIODNOISE:
	rra 
    jr nc, PLY_AKM_PSES_H_AFTERRETRIG
    ld d, a
    ld a, #0xff
    ld (PLY_AKM_SETREG13OLD), a
    ld a, d
PLY_AKM_PSES_H_AFTERRETRIG:
PLY_AKM_ROM_BUFFERSIZE:
	and #0x7
    add a, #0x8
    ld (PLY_AKM_SETREG13), a
    rl b
    call PLY_AKM_PSES_READNOISEIFNEEDEDANDOPENORCLOSENOISECHANNEL
    call PLY_AKM_PSES_READHARDWAREPERIOD
    ld a, #0x10
    jp PLY_AKM_PSES_MANAGEVOLUMEFROMA_HARD
PLY_AKM_PSES_READNOISEIFNEEDEDANDOPENORCLOSENOISECHANNEL:
	jr c, PLY_AKM_PSES_READNOISEANDOPENNOISECHANNEL_OPENNOISE
    set 5, c
    ret 
PLY_AKM_PSES_READNOISEANDOPENNOISECHANNEL_OPENNOISE:
	ld a, (hl)
    ld (PLY_AKM_NOISEREGISTER), a
    inc hl
    res 5, c
    ret 
PLY_AKM_PSES_READHARDWAREPERIOD:
	ld a, (hl)
    ld (PLY_AKM_REG11), a
    inc hl
    ld a, (hl)
    ld (PLY_AKM_REG12), a
    inc hl
    ret 
PLY_AKM_PSES_READSOFTWAREPERIOD:
	ld a, (hl)
    ld +5(iy), a
    inc hl
    ld a, (hl)
    ld +9(iy), a
    inc hl
    ret 
PLY_AKM_PSES_MANAGEVOLUMEFROMA_FILTER4BITS:
	and #0xf
PLY_AKM_PSES_MANAGEVOLUMEFROMA_HARD:
	sub +2(ix)
    jr nc, PLY_AKM_PSES_MVFA_NOOVERFLOW
    xor a
PLY_AKM_PSES_MVFA_NOOVERFLOW:
	ld +1(iy), a
    ret 
__endasm;
}

// Initialize a music. HL=music address, A=subsong index (>=0)
void AKM_Init(const void* data, u16 sng)
{
__asm
	ld a, e ; convert C parameter
PLY_AKM_INIT:
	ld de, #PLY_AKM_PTINSTRUMENTS
    ldi
    ldi
    ld de, #PLY_AKM_PTARPEGGIOS
    ldi
    ldi
    ld de, #PLY_AKM_PTPITCHES
    ldi
    ldi
    add a, a
    ld e, a
    ld d, #0x0
    add hl, de
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    ld ix, #PLY_AKM_INITVARS_START
    ld a, #0xd
PLY_AKM_INITVARS_LOOP:
	ld e, +0(ix)
    ld d, +1(ix)
    inc ix
    inc ix
    ldi
    dec a
    jr nz, PLY_AKM_INITVARS_LOOP
    ld (PLY_AKM_PATTERNREMAININGHEIGHT), a
    ex de, hl
    ld hl, #PLY_AKM_PTLINKER
    ld (hl), e
    inc hl
    ld (hl), d
    ld hl, #PLY_AKM_TRACK1_WAITEMPTYCELL
    ld de, #PLY_AKM_TRACK1_TRANSPOSITION
    ld bc, #0xd0de
    ld (hl), a
    ldir
    ld (PLY_AKM_RT_READEFFECTSFLAG), a
    ld a, (PLY_AKM_SPEED)
    dec a
    ld (PLY_AKM_TICKCOUNTER), a
    ld hl, (PLY_AKM_PTINSTRUMENTS)
    ld e, (hl)
    inc hl
    ld d, (hl)
    inc de
    ld (PLY_AKM_TRACK1_PTINSTRUMENT), de
    ld (PLY_AKM_TRACK2_PTINSTRUMENT), de
    ld (PLY_AKM_TRACK3_PTINSTRUMENT), de
    ld hl, #0x0
    ld (PLY_AKM_CHANNEL1_SOUNDEFFECTDATA), hl
    ld (PLY_AKM_CHANNEL2_SOUNDEFFECTDATA), hl
    ld (PLY_AKM_CHANNEL3_SOUNDEFFECTDATA), hl
    ld ix, #PLY_AKM_REGISTERSFORROM
    ld iy, #PLY_AKM_TRACK1_REGISTERS
    ld bc, #PLY_AKM_SENDPSGREGISTER
    ld de, #0x4
PLY_AKM_INITROM_LOOP:
	ld a, +0(ix)
    ld h, a
    inc ix
    and #0x3f
    ld +0(iy), a
    ld +1(iy), #0x0
    ld a, h
    and #0xc0
    jr nz, PLY_AKM_INITROM_SPECIAL
    ld +2(iy), c
    ld +3(iy), b
    add iy, de
    jr PLY_AKM_INITROM_LOOP
PLY_AKM_INITROM_SPECIAL:
	rl h
    jr c, PLY_AKM_INITROM_WRITEENDCODE
    ld bc, #PLY_AKM_SENDPSGREGISTERR13
    ld +2(iy), c
    ld +3(iy), b
    ld bc, #PLY_AKM_SENDPSGREGISTERAFTERPOP
    ld +4(iy), c
    ld +5(iy), b
    add iy, de
PLY_AKM_INITROM_WRITEENDCODE:
	ld bc, #PLY_AKM_SENDPSGREGISTEREND
    ld +2(iy), c
    ld +3(iy), b
    ret 
PLY_AKM_REGISTERSFORROM:
	.db 0x8
    .db 0x0
    .db 0x1
    .db 0x9
    .db 0x2
    .db 0x3
    .db 0xa
    .db 0x4
    .db 0x5
    .db 0x6
    .db 0x7
    .db 0xb
    .db 0x4c
PLY_AKM_INITVARS_START:
	.dw PLY_AKM_NOTEINDEXTABLE
    .dw PLY_AKM_NOTEINDEXTABLE+1
    .dw PLY_AKM_TRACKINDEX
    .dw PLY_AKM_TRACKINDEX+1
    .dw PLY_AKM_SPEED
    .dw PLY_AKM_PRIMARYINSTRUMENT
    .dw PLY_AKM_SECONDARYINSTRUMENT
    .dw PLY_AKM_PRIMARYWAIT
    .dw PLY_AKM_SECONDARYWAIT
    .dw PLY_AKM_DEFAULTSTARTNOTEINTRACKS
    .dw PLY_AKM_DEFAULTSTARTINSTRUMENTINTRACKS
    .dw PLY_AKM_DEFAULTSTARTWAITINTRACKS
    .dw PLY_AKM_FLAGNOTEANDEFFECTINCELL
PLY_AKM_INITVARS_END:
__endasm;
}

// Stop the music    
void AKM_Stop()
{
__asm
PLY_AKM_STOP:
	ld (PLY_AKM_SAVESP), sp
    xor a
    ld (PLY_AKM_TRACK1_VOLUME), a
    ld (PLY_AKM_TRACK2_VOLUME), a
    ld (PLY_AKM_TRACK3_VOLUME), a
    ld a, #0xbf
    ld (PLY_AKM_MIXERREGISTER), a
    jp PLY_AKM_SENDPSG
__endasm;
}

// Play a music frame
void AKM_Decode()
{
__asm
PLY_AKM_PLAY:
	ld (PLY_AKM_SAVESP), sp
    ld a, (PLY_AKM_SPEED)
    ld b, a
    ld a, (PLY_AKM_TICKCOUNTER)
    inc a
    cp b
    jp nz, PLY_AKM_TICKCOUNTERMANAGED
    ld a, (PLY_AKM_PATTERNREMAININGHEIGHT)
    sub #0x1
    jr c, PLY_AKM_LINKER
    ld (PLY_AKM_PATTERNREMAININGHEIGHT), a
    jr PLY_AKM_READLINE
PLY_AKM_LINKER:
	ld de, (PLY_AKM_TRACKINDEX)
    exx
    ld hl, (PLY_AKM_PTLINKER)
PLY_AKM_LINKERPOSTPT:
	xor a
    ld (PLY_AKM_TRACK1_WAITEMPTYCELL), a
    ld (PLY_AKM_TRACK2_WAITEMPTYCELL), a
    ld (PLY_AKM_TRACK3_WAITEMPTYCELL), a
    ld a, (PLY_AKM_DEFAULTSTARTNOTEINTRACKS)
    ld (PLY_AKM_TRACK1_ESCAPENOTE), a
    ld (PLY_AKM_TRACK2_ESCAPENOTE), a
    ld (PLY_AKM_TRACK3_ESCAPENOTE), a
    ld a, (PLY_AKM_DEFAULTSTARTINSTRUMENTINTRACKS)
    ld (PLY_AKM_TRACK1_ESCAPEINSTRUMENT), a
    ld (PLY_AKM_TRACK2_ESCAPEINSTRUMENT), a
    ld (PLY_AKM_TRACK3_ESCAPEINSTRUMENT), a
    ld a, (PLY_AKM_DEFAULTSTARTWAITINTRACKS)
    ld (PLY_AKM_TRACK1_ESCAPEWAIT), a
    ld (PLY_AKM_TRACK2_ESCAPEWAIT), a
    ld (PLY_AKM_TRACK3_ESCAPEWAIT), a
    ld b, (hl)
    inc hl
    rr b
    jr nc, PLY_AKM_LINKERAFTERSPEEDCHANGE
    ld a, (hl)
    inc hl
    or a
    jr nz, PLY_AKM_LINKERSPEEDCHANGE
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    jr PLY_AKM_LINKERPOSTPT
PLY_AKM_LINKERSPEEDCHANGE:
	ld (PLY_AKM_SPEED), a
PLY_AKM_LINKERAFTERSPEEDCHANGE:
	rr b
    jr nc, PLY_AKM_LINKERUSEPREVIOUSHEIGHT
    ld a, (hl)
    inc hl
    ld (PLY_AKM_LINKERPREVIOUSREMAININGHEIGHT), a
    jr PLY_AKM_LINKERSETREMAININGHEIGHT
PLY_AKM_LINKERUSEPREVIOUSHEIGHT:
	ld a, (PLY_AKM_LINKERPREVIOUSREMAININGHEIGHT)
PLY_AKM_LINKERSETREMAININGHEIGHT:
	ld (PLY_AKM_PATTERNREMAININGHEIGHT), a
    ld ix, #PLY_AKM_TRACK1_WAITEMPTYCELL
    call PLY_AKM_CHECKTRANSPOSITIONANDTRACK
    ld ix, #PLY_AKM_TRACK2_WAITEMPTYCELL
    call PLY_AKM_CHECKTRANSPOSITIONANDTRACK
    ld ix, #PLY_AKM_TRACK3_WAITEMPTYCELL
    call PLY_AKM_CHECKTRANSPOSITIONANDTRACK
    ld (PLY_AKM_PTLINKER), hl
PLY_AKM_READLINE:
	ld de, (PLY_AKM_PTINSTRUMENTS)
    ld bc, (PLY_AKM_NOTEINDEXTABLE)
    exx
    ld ix, #PLY_AKM_TRACK1_WAITEMPTYCELL
    call PLY_AKM_READTRACK
    ld ix, #PLY_AKM_TRACK2_WAITEMPTYCELL
    call PLY_AKM_READTRACK
    ld ix, #PLY_AKM_TRACK3_WAITEMPTYCELL
    call PLY_AKM_READTRACK
    xor a
PLY_AKM_TICKCOUNTERMANAGED:
	ld (PLY_AKM_TICKCOUNTER), a
    ld de, #PLY_AKM_PERIODTABLE
    exx
    ld c, #0xe0
    ld ix, #PLY_AKM_TRACK1_WAITEMPTYCELL
    call PLY_AKM_MANAGEEFFECTS
    ld iy, #PLY_AKM_TRACK1_REGISTERS
    call PLY_AKM_PLAYSOUNDSTREAM
    srl c
    ld ix, #PLY_AKM_TRACK2_WAITEMPTYCELL
    call PLY_AKM_MANAGEEFFECTS
    ld iy, #PLY_AKM_TRACK2_REGISTERS
    call PLY_AKM_PLAYSOUNDSTREAM
    scf
    rr c
    ld ix, #PLY_AKM_TRACK3_WAITEMPTYCELL
    call PLY_AKM_MANAGEEFFECTS
    ld iy, #PLY_AKM_TRACK3_REGISTERS
    call PLY_AKM_PLAYSOUNDSTREAM
    ld a, c
    call PLY_AKM_PLAYSOUNDEFFECTSSTREAM
PLY_AKM_SENDPSG:
	ld sp, #PLY_AKM_TRACK1_REGISTERS
PLY_AKM_SENDPSGREGISTER:
	pop hl
PLY_AKM_SENDPSGREGISTERAFTERPOP:
	ld a, l
    out (0xa0), a
    ld a, h
    out (0xa1), a
    ret 
PLY_AKM_SENDPSGREGISTERR13:
	ld a, (PLY_AKM_SETREG13OLD)
    ld b, a
    ld a, (PLY_AKM_SETREG13)
    cp b
    jr z, PLY_AKM_SENDPSGREGISTEREND
    ld (PLY_AKM_SETREG13OLD), a
    ld h, a
    ld l, #0xd
    ret 
PLY_AKM_SENDPSGREGISTEREND:
	ld sp, (PLY_AKM_SAVESP)
    ret 
PLY_AKM_CHECKTRANSPOSITIONANDTRACK:
	rr b
    jr nc, PLY_AKM_CHECKTRANSPOSITIONANDTRACK_AFTERTRANSPOSITION
    ld a, (hl)
    ld +1(ix), a
    inc hl
PLY_AKM_CHECKTRANSPOSITIONANDTRACK_AFTERTRANSPOSITION:
	rr b
    jr nc, PLY_AKM_CHECKTRANSPOSITIONANDTRACK_NONEWTRACK
    ld a, (hl)
    inc hl
    sla a
    jr nc, PLY_AKM_CHECKTRANSPOSITIONANDTRACK_TRACKOFFSET
    exx
    ld l, a
    ld h, #0x0
    add hl, de
    ld a, (hl)
    ld +2(ix), a
    ld +4(ix), a
    inc hl
    ld a, (hl)
    ld +2(ix), a
    ld +4(ix), a
    exx
    ret 
PLY_AKM_CHECKTRANSPOSITIONANDTRACK_TRACKOFFSET:
	rra 
    ld d, a
    ld e, (hl)
    inc hl
    ld c, l
    ld a, h
    add hl, de
    .db 0xdd
    .db 0x75
    .db 0x2
    .db 0xdd
    .db 0x74
    .db 0x2
    .db 0xdd
    .db 0x75
    .db 0x4
    .db 0xdd
    .db 0x74
    .db 0x4
    ld l, c
    ld h, a
    ret 
PLY_AKM_CHECKTRANSPOSITIONANDTRACK_NONEWTRACK:
	ld a, +2(ix)
    ld +4(ix), a
    ld a, +2(ix)
    ld +4(ix), a
    ret 
PLY_AKM_READTRACK:
	ld a, +0(ix)
    sub #0x1
    jr c, PLY_AKM_RT_NOEMPTYCELL
    ld +0(ix), a
    ret 
PLY_AKM_RT_NOEMPTYCELL:
	ld l, +4(ix)
    ld h, +4(ix)
PLY_AKM_RT_GETDATABYTE:
	ld b, (hl)
    inc hl
    ld a, (PLY_AKM_FLAGNOTEANDEFFECTINCELL)
    ld c, a
    ld a, b
    and #0xf
    cp c
    jr c, PLY_AKM_RT_NOTEREFERENCE
    sub #0xc
    jr z, PLY_AKM_RT_NOTEANDEFFECTS
    dec a
    jr z, PLY_AKM_RT_NONOTEMAYBEEFFECTS
    dec a
    jr z, PLY_AKM_RT_NEWESCAPENOTE
    ld a, +7(ix)
    jr PLY_AKM_RT_AFTERNOTEREAD
PLY_AKM_RT_NEWESCAPENOTE:
	ld a, (hl)
    ld +7(ix), a
    inc hl
    jr PLY_AKM_RT_AFTERNOTEREAD
PLY_AKM_RT_NOTEANDEFFECTS:
	dec a
    ld (PLY_AKM_RT_READEFFECTSFLAG), a
    jr PLY_AKM_RT_GETDATABYTE
PLY_AKM_RT_NONOTEMAYBEEFFECTS:
	bit 4, b
    jr z, PLY_AKM_RT_READWAITFLAGS
    ld a, b
    ld (PLY_AKM_RT_READEFFECTSFLAG), a
    jr PLY_AKM_RT_READWAITFLAGS
PLY_AKM_RT_NOTEREFERENCE:
	exx
    ld l, a
    ld h, #0x0
    add hl, bc
    ld a, (hl)
    exx
PLY_AKM_RT_AFTERNOTEREAD:
	add a, +1(ix)
    ld +6(ix), a
    ld a, b
    and #0x30
    jr z, PLY_AKM_RT_SAMEESCAPEINSTRUMENT
    cp #0x10
    jr z, PLY_AKM_RT_PRIMARYINSTRUMENT
    cp #0x20
    jr z, PLY_AKM_RT_SECONDARYINSTRUMENT
    ld a, (hl)
    inc hl
    ld +8(ix), a
    jr PLY_AKM_RT_STORECURRENTINSTRUMENT
PLY_AKM_RT_SAMEESCAPEINSTRUMENT:
	ld a, +8(ix)
    jr PLY_AKM_RT_STORECURRENTINSTRUMENT
PLY_AKM_RT_SECONDARYINSTRUMENT:
	ld a, (PLY_AKM_SECONDARYINSTRUMENT)
    jr PLY_AKM_RT_STORECURRENTINSTRUMENT
PLY_AKM_RT_PRIMARYINSTRUMENT:
	ld a, (PLY_AKM_PRIMARYINSTRUMENT)
PLY_AKM_RT_STORECURRENTINSTRUMENT:
	exx
    add a, a
    ld l, a
    ld h, #0x0
    add hl, de
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    ld a, (hl)
    inc hl
    ld +13(ix), a
    .db 0xdd
    .db 0x75
    .db 0xa
    .db 0xdd
    .db 0x74
    .db 0xa
    exx
    xor a
    ld +12(ix), a
    ld +15(ix), a
    ld +16(ix), a
    ld +16(ix), a
    ld +24(ix), a
    ld +25(ix), a
    ld a, +27(ix)
    ld +26(ix), a
    ld +32(ix), a
    ld +33(ix), a
    ld a, +35(ix)
    ld +34(ix), a
PLY_AKM_RT_READWAITFLAGS:
	ld a, b
    and #0xc0
    jr z, PLY_AKM_RT_SAMEESCAPEWAIT
    cp #0x40
    jr z, PLY_AKM_RT_PRIMARYWAIT
    cp #0x80
    jr z, PLY_AKM_RT_SECONDARYWAIT
    ld a, (hl)
    inc hl
    ld +9(ix), a
    jr PLY_AKM_RT_STORECURRENTWAIT
PLY_AKM_RT_SAMEESCAPEWAIT:
	ld a, +9(ix)
    jr PLY_AKM_RT_STORECURRENTWAIT
PLY_AKM_RT_PRIMARYWAIT:
	ld a, (PLY_AKM_PRIMARYWAIT)
    jr PLY_AKM_RT_STORECURRENTWAIT
PLY_AKM_RT_SECONDARYWAIT:
	ld a, (PLY_AKM_SECONDARYWAIT)
PLY_AKM_RT_STORECURRENTWAIT:
	ld +0(ix), a
    ld a, (PLY_AKM_RT_READEFFECTSFLAG)
    or a
    jr nz, PLY_AKM_RT_READEFFECTS
PLY_AKM_RT_AFTEREFFECTS:
	.db 0xdd
    .db 0x75
    .db 0x4
    .db 0xdd
    .db 0x74
    .db 0x4
    ret 
PLY_AKM_RT_READEFFECTS:
	xor a
    ld (PLY_AKM_RT_READEFFECTSFLAG), a
PLY_AKM_RT_READEFFECT:
	ld iy, #PLY_AKM_EFFECTTABLE
    ld b, (hl)
    ld a, b
    inc hl
    and #0xe
    ld e, a
    ld d, #0x0
    add iy, de
    ld a, b
    rra 
    rra 
    rra 
    rra 
    and #0xf
    jp (iy)
PLY_AKM_RT_READEFFECT_RETURN:
	bit 0, b
    jr nz, PLY_AKM_RT_READEFFECT
    jr PLY_AKM_RT_AFTEREFFECTS
PLY_AKM_RT_WAITLONG:
	ld a, (hl)
    inc hl
    ld +0(ix), a
    jr PLY_AKM_RT_CELLREAD
PLY_AKM_RT_WAITSHORT:
	ld a, b
    rlca 
    rlca 
    and #0x3
    ld +0(ix), a
PLY_AKM_RT_CELLREAD:
	.db 0xdd
    .db 0x75
    .db 0x4
    .db 0xdd
    .db 0x74
    .db 0x4
    ret 
PLY_AKM_MANAGEEFFECTS:
	ld a, +15(ix)
    or a
    jr z, PLY_AKM_ME_PITCHUPDOWNFINISHED
    ld l, +18(ix)
    ld h, +16(ix)
    ld e, +19(ix)
    ld d, +19(ix)
    ld a, +16(ix)
    bit 7, d
    jr nz, PLY_AKM_ME_PITCHUPDOWN_NEGATIVESPEED
PLY_AKM_ME_PITCHUPDOWN_POSITIVESPEED:
	add hl, de
    adc a, #0x0
    jr PLY_AKM_ME_PITCHUPDOWN_SAVE
PLY_AKM_ME_PITCHUPDOWN_NEGATIVESPEED:
	res 7, d
    or a
    sbc hl, de
    sbc a, #0x0
PLY_AKM_ME_PITCHUPDOWN_SAVE:
	ld +16(ix), a
    .db 0xdd
    .db 0x75
    .db 0x12
    .db 0xdd
    .db 0x74
    .db 0x10
PLY_AKM_ME_PITCHUPDOWNFINISHED:
	ld a, +21(ix)
    or a
    jr z, PLY_AKM_ME_ARPEGGIOTABLEFINISHED
    ld e, +22(ix)
    ld d, +22(ix)
    ld l, +24(ix)
    ld h, #0x0
    add hl, de
    ld a, (hl)
    sra a
    ld +28(ix), a
    ld a, +25(ix)
    cp +26(ix)
    jr c, PLY_AKM_ME_ARPEGGIOTABLE_SPEEDNOTREACHED
    ld +25(ix), #0x0
    inc +24(ix)
    inc hl
    ld a, (hl)
    rra 
    jr nc, PLY_AKM_ME_ARPEGGIOTABLEFINISHED
    ld l, a
    ld +24(ix), a
    jr PLY_AKM_ME_ARPEGGIOTABLEFINISHED
PLY_AKM_ME_ARPEGGIOTABLE_SPEEDNOTREACHED:
	inc a
    ld +25(ix), a
PLY_AKM_ME_ARPEGGIOTABLEFINISHED:
	ld a, +29(ix)
    or a
    ret z
    ld l, +30(ix)
    ld h, +30(ix)
    ld e, +32(ix)
    ld d, #0x0
    add hl, de
    ld a, (hl)
    sra a
    jp p, PLY_AKM_ME_PITCHTABLEENDNOTREACHED_POSITIVE
    dec d
PLY_AKM_ME_PITCHTABLEENDNOTREACHED_POSITIVE:
	ld +36(ix), a
    .db 0xdd
    .db 0x72
    .db 0x24
    ld a, +33(ix)
    cp +34(ix)
    jr c, PLY_AKM_ME_PITCHTABLE_SPEEDNOTREACHED
    ld +33(ix), #0x0
    inc +32(ix)
    inc hl
    ld a, (hl)
    rra 
    ret nc
    ld l, a
    ld +32(ix), a
    ret 
PLY_AKM_ME_PITCHTABLE_SPEEDNOTREACHED:
	inc a
    ld +33(ix), a
    ret 
PLY_AKM_PLAYSOUNDSTREAM:
	ld l, +10(ix)
    ld h, +10(ix)
PLY_AKM_PSS_READFIRSTBYTE:
	ld a, (hl)
    ld b, a
    inc hl
    rra 
    jr c, PLY_AKM_PSS_SOFTORSOFTANDHARD
    rra 
    jr c, PLY_AKM_PSS_SOFTWARETOHARDWARE
    rra 
    jr nc, PLY_AKM_PSS_NSNH_NOTENDOFSOUND
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    .db 0xdd
    .db 0x75
    .db 0xa
    .db 0xdd
    .db 0x74
    .db 0xa
    jr PLY_AKM_PSS_READFIRSTBYTE
PLY_AKM_PSS_NSNH_NOTENDOFSOUND:
	set 2, c
    call PLY_AKM_PSS_SHARED_ADJUSTVOLUME
    ld +1(iy), a
    rl b
    call c, PLY_AKM_PSS_READNOISE
    jr PLY_AKM_PSS_SHARED_STOREINSTRUMENTPOINTER
PLY_AKM_PSS_SOFTORSOFTANDHARD:
	rra 
    jr c, PLY_AKM_PSS_SOFTANDHARD
    call PLY_AKM_PSS_SHARED_ADJUSTVOLUME
    ld +1(iy), a
    ld d, #0x0
    rl b
    jr nc, PLY_AKM_PSS_S_AFTERARPANDORNOISE
    ld a, (hl)
    inc hl
    sra a
    ld d, a
    call c, PLY_AKM_PSS_READNOISE
PLY_AKM_PSS_S_AFTERARPANDORNOISE:
	ld a, d
    call PLY_AKM_CALCULATEPERIODFORBASENOTE
    rl b
    call c, PLY_AKM_READPITCHANDADDTOPERIOD
    exx
    ld +5(iy), l
    ld +9(iy), h
    exx
PLY_AKM_PSS_SHARED_STOREINSTRUMENTPOINTER:
	ld a, +12(ix)
    cp +13(ix)
    jr nc, PLY_AKM_PSS_S_SPEEDREACHED
    inc +12(ix)
    ret 
PLY_AKM_PSS_S_SPEEDREACHED:
	.db 0xdd
    .db 0x75
    .db 0xa
    .db 0xdd
    .db 0x74
    .db 0xa
    ld +12(ix), #0x0
    ret 
PLY_AKM_PSS_SOFTANDHARD:
	call PLY_AKM_PSS_SHARED_READENVBITPITCHARP_SOFTPERIOD_HARDVOL_HARDENV
    ld a, (hl)
    ld (PLY_AKM_REG11), a
    inc hl
    ld a, (hl)
    ld (PLY_AKM_REG12), a
    inc hl
    jr PLY_AKM_PSS_SHARED_STOREINSTRUMENTPOINTER
PLY_AKM_PSS_SOFTWARETOHARDWARE:
	call PLY_AKM_PSS_SHARED_READENVBITPITCHARP_SOFTPERIOD_HARDVOL_HARDENV
    ld a, b
    rlca 
    rlca 
    rlca 
    rlca 
    and #0x7
    exx
    jr z, PLY_AKM_PSS_STH_RATIOEND
PLY_AKM_PSS_STH_RATIOLOOP:
	srl h
    rr l
    dec a
    jr nz, PLY_AKM_PSS_STH_RATIOLOOP
    jr nc, PLY_AKM_PSS_STH_RATIOEND
    inc hl
PLY_AKM_PSS_STH_RATIOEND:
	ld a, l
    ld (PLY_AKM_REG11), a
    ld a, h
    ld (PLY_AKM_REG12), a
    exx
    jr PLY_AKM_PSS_SHARED_STOREINSTRUMENTPOINTER
PLY_AKM_PSS_SHARED_READENVBITPITCHARP_SOFTPERIOD_HARDVOL_HARDENV:
	and #0x2
    add a, #0x8
    ld (PLY_AKM_SETREG13), a
    ld +1(iy), #0x10
    xor a
    bit 7, b
    jr z, PLY_AKM_PSS_SHARED_RENVBAP_AFTERARPEGGIO
    ld a, (hl)
    inc hl
PLY_AKM_PSS_SHARED_RENVBAP_AFTERARPEGGIO:
	call PLY_AKM_CALCULATEPERIODFORBASENOTE
    bit 2, b
    call nz, PLY_AKM_READPITCHANDADDTOPERIOD
    exx
    ld +5(iy), l
    ld +9(iy), h
    exx
    ret 
PLY_AKM_PSS_SHARED_ADJUSTVOLUME:
	and #0xf
    sub +14(ix)
    ret nc
    xor a
    ret 
PLY_AKM_PSS_READNOISE:
	ld a, (hl)
    inc hl
    ld (PLY_AKM_NOISEREGISTER), a
    res 5, c
    ret 
PLY_AKM_CALCULATEPERIODFORBASENOTE:
	exx
    ld h, #0x0
    add a, +6(ix)
    add a, +28(ix)
    ld bc, #0xff0c
PLY_AKM_FINDOCTAVE_LOOP:
	inc b
    sub c
    jr nc, PLY_AKM_FINDOCTAVE_LOOP
    add a, c
    add a, a
    ld l, a
    ld h, #0x0
    add hl, de
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    ld a, b
    or a
    jr z, PLY_AKM_FINDOCTAVE_OCTAVESHIFTLOOP_FINISHED
PLY_AKM_FINDOCTAVE_OCTAVESHIFTLOOP:
	srl h
    rr l
    djnz PLY_AKM_FINDOCTAVE_OCTAVESHIFTLOOP
PLY_AKM_FINDOCTAVE_OCTAVESHIFTLOOP_FINISHED:
	jr nc, PLY_AKM_FINDOCTAVE_FINISHED
    inc hl
PLY_AKM_FINDOCTAVE_FINISHED:
	ld a, +29(ix)
    or a
    jr z, PLY_AKM_CALCULATEPERIODFORBASENOTE_NOPITCHTABLE
    ld c, +36(ix)
    ld b, +36(ix)
    add hl, bc
PLY_AKM_CALCULATEPERIODFORBASENOTE_NOPITCHTABLE:
	ld c, +16(ix)
    ld b, +16(ix)
    add hl, bc
    exx
    ret 
PLY_AKM_READPITCHANDADDTOPERIOD:
	ld a, (hl)
    inc hl
    exx
    ld c, a
    exx
    ld a, (hl)
    inc hl
    exx
    ld b, a
    add hl, bc
    exx
    ret 
PLY_AKM_EFFECTRESETWITHVOLUME:
	ld +14(ix), a
    xor a
    ld +15(ix), a
    ld +21(ix), a
    ld +28(ix), a
    ld +29(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTVOLUME:
	ld +14(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTFORCEINSTRUMENTSPEED:
	call PLY_AKM_EFFECTREADIFESCAPE
    ld +13(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTFORCEPITCHSPEED:
	call PLY_AKM_EFFECTREADIFESCAPE
    ld +34(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTFORCEARPEGGIOSPEED:
	call PLY_AKM_EFFECTREADIFESCAPE
    ld +26(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTTABLE:
	jr PLY_AKM_EFFECTRESETWITHVOLUME
    jr PLY_AKM_EFFECTVOLUME
    jr PLY_AKM_EFFECTPITCHUPDOWN
    jr PLY_AKM_EFFECTARPEGGIOTABLE
    jr PLY_AKM_EFFECTPITCHTABLE
    jr PLY_AKM_EFFECTFORCEINSTRUMENTSPEED
    jr PLY_AKM_EFFECTFORCEARPEGGIOSPEED
    jr PLY_AKM_EFFECTFORCEPITCHSPEED
PLY_AKM_EFFECTPITCHUPDOWN:
	rra 
    jr nc, PLY_AKM_EFFECTPITCHUPDOWN_DEACTIVATED
    ld +15(ix), #0xff
    ld a, (hl)
    inc hl
    ld +19(ix), a
    ld a, (hl)
    inc hl
    ld +19(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTPITCHUPDOWN_DEACTIVATED:
	ld +15(ix), #0x0
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTARPEGGIOTABLE:
	call PLY_AKM_EFFECTREADIFESCAPE
    ld +21(ix), a
    or a
    jr z, PLY_AKM_EFFECTARPEGGIOTABLE_STOP
    add a, a
    exx
    ld l, a
    ld h, #0x0
    ld bc, (PLY_AKM_PTARPEGGIOS)
    add hl, bc
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    ld a, (hl)
    inc hl
    ld +27(ix), a
    ld +26(ix), a
    .db 0xdd
    .db 0x75
    .db 0x16
    .db 0xdd
    .db 0x74
    .db 0x16
    ld bc, (PLY_AKM_NOTEINDEXTABLE)
    exx
    xor a
    ld +24(ix), a
    ld +25(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTARPEGGIOTABLE_STOP:
	ld +28(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTPITCHTABLE:
	call PLY_AKM_EFFECTREADIFESCAPE
    ld +29(ix), a
    or a
    jp z, PLY_AKM_RT_READEFFECT_RETURN
    add a, a
    exx
    ld l, a
    ld h, #0x0
    ld bc, (PLY_AKM_PTPITCHES)
    add hl, bc
    ld a, (hl)
    inc hl
    ld h, (hl)
    ld l, a
    ld a, (hl)
    inc hl
    ld +35(ix), a
    ld +34(ix), a
    .db 0xdd
    .db 0x75
    .db 0x1e
    .db 0xdd
    .db 0x74
    .db 0x1e
    ld bc, (PLY_AKM_NOTEINDEXTABLE)
    exx
    xor a
    ld +32(ix), a
    ld +33(ix), a
    jp PLY_AKM_RT_READEFFECT_RETURN
PLY_AKM_EFFECTREADIFESCAPE:
	cp #0xf
    ret c
    ld a, (hl)
    inc hl
    ret 
PLY_AKM_PERIODTABLE:
	.dw 0x1a7a
    .dw 0x18fe
    .dw 0x1797
    .dw 0x1644
    .dw 0x1504
    .dw 0x13d6
    .dw 0x12b9
    .dw 0x11ac
    .dw 0x10ae
    .dw 0xfbe
    .dw 0xedc
    .dw 0xe07
PLY_AKM_CHANNEL1_SOUNDEFFECTDATA = 0xd057
PLY_AKM_CHANNEL2_SOUNDEFFECTDATA = 0xd05f
PLY_AKM_CHANNEL3_SOUNDEFFECTDATA = 0xd067
PLY_AKM_DEFAULTSTARTINSTRUMENTINTRACKS = 0xd00f
PLY_AKM_DEFAULTSTARTNOTEINTRACKS = 0xd00e
PLY_AKM_DEFAULTSTARTWAITINTRACKS = 0xd010
PLY_AKM_FLAGNOTEANDEFFECTINCELL = 0xd015
PLY_AKM_LINKERPREVIOUSREMAININGHEIGHT = 0xd017
PLY_AKM_MIXERREGISTER = 0xd046
PLY_AKM_NOISEREGISTER = 0xd042
PLY_AKM_NOTEINDEXTABLE = 0xd008
PLY_AKM_PATTERNREMAININGHEIGHT = 0xd016
PLY_AKM_PRIMARYINSTRUMENT = 0xd011
PLY_AKM_PRIMARYWAIT = 0xd013
PLY_AKM_PTARPEGGIOS = 0xd002
PLY_AKM_PTINSTRUMENTS = 0xd000
PLY_AKM_PTLINKER = 0xd006
PLY_AKM_PTPITCHES = 0xd004
PLY_AKM_PTSOUNDEFFECTTABLE = 0xd055
PLY_AKM_REG11 = 0xd04a
PLY_AKM_REG12 = 0xd04e
PLY_AKM_RT_READEFFECTSFLAG = 0xd01c
PLY_AKM_SAVESP = 0xd00c
PLY_AKM_SECONDARYINSTRUMENT = 0xd012
PLY_AKM_SECONDARYWAIT = 0xd014
PLY_AKM_SETREG13 = 0xd01b
PLY_AKM_SETREG13OLD = 0xd01a
PLY_AKM_SPEED = 0xd018
PLY_AKM_TICKCOUNTER = 0xd019
PLY_AKM_TRACK1_ESCAPEINSTRUMENT = 0xd074
PLY_AKM_TRACK1_ESCAPENOTE = 0xd073
PLY_AKM_TRACK1_ESCAPEWAIT = 0xd075
PLY_AKM_TRACK1_PTINSTRUMENT = 0xd076
PLY_AKM_TRACK1_REGISTERS = 0xd01d
PLY_AKM_TRACK1_TRANSPOSITION = 0xd06d
PLY_AKM_TRACK1_VOLUME = 0xd01e
PLY_AKM_TRACK1_WAITEMPTYCELL = 0xd06c
PLY_AKM_TRACK2_ESCAPEINSTRUMENT = 0xd09a
PLY_AKM_TRACK2_ESCAPENOTE = 0xd099
PLY_AKM_TRACK2_ESCAPEWAIT = 0xd09b
PLY_AKM_TRACK2_PTINSTRUMENT = 0xd09c
PLY_AKM_TRACK2_REGISTERS = 0xd029
PLY_AKM_TRACK2_VOLUME = 0xd02a
PLY_AKM_TRACK2_WAITEMPTYCELL = 0xd092
PLY_AKM_TRACK3_ESCAPEINSTRUMENT = 0xd0c0
PLY_AKM_TRACK3_ESCAPENOTE = 0xd0bf
PLY_AKM_TRACK3_ESCAPEWAIT = 0xd0c1
PLY_AKM_TRACK3_PTINSTRUMENT = 0xd0c2
PLY_AKM_TRACK3_REGISTERS = 0xd035
PLY_AKM_TRACK3_VOLUME = 0xd036
PLY_AKM_TRACK3_WAITEMPTYCELL = 0xd0b8
PLY_AKM_TRACKINDEX = 0xd00a
__endasm;                 
}                         
