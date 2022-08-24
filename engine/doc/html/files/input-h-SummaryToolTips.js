﻿NDSummary.OnToolTipsLoaded("File:input.h",{380:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Direct access to joystick</div></div>",381:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype381\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">u8 Joystick_Read(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port</td></tr></table></td><td class=\"PAfterParameters\">) __FASTCALL</td></tr></table></div></div><div class=\"TTSummary\">Get the current joystick information</div></div>",362:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype362\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">void</span> Joystick_Update()</div></div><div class=\"TTSummary\">Update both joystick stats at once and store the result Only available when INPUT_JOY_UPDATE is TRUE</div></div>",387:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype387\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 Joystick_GetDirection(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current direction of the given joystick If INPUT_JOY_UPDATE is TRUE, this function use data retreived by Joystick_Update().&nbsp; Otherwise, this function read I/O data.</div></div>",382:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype382\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 Joystick_GetDirectionPushed(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current direction of the given joystick if different from previous one Only available if INPUT_JOY_UPDATE is TRUE.</div></div>",383:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype383\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline bool</span> Joystick_IsButtonPressed(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">trigger</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current trigger status of the given joystick If INPUT_JOY_UPDATE is TRUE, this function use data retreived by Joystick_Update().&nbsp; Otherwise, this function read I/O data.</div></div>",385:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype385\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline bool</span> Joystick_IsButtonPushed(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">trigger</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current trigger status of the given joystick Only available if INPUT_JOY_UPDATE is TRUE.</div></div>",596:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">General purpose ports device detection</div></div>",597:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype597\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 Input_Detect(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Detect device plugged in General purpose ports</div></div>",598:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Direct access to mouse</div></div>",599:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype599\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Mouse_Read(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">port,</td></tr><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",600:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype600\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> i8 Mouse_GetOffsetX(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",601:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype601\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> i8 Mouse_GetOffsetY(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",602:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype602\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> i8 Mouse_GetAdjustedOffsetX(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">spd</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",603:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype603\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> i8 Mouse_GetAdjustedOffsetY(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">spd</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",604:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype604\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline bool</span> Mouse_IsButtonPress(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">btn</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",605:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype605\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline bool</span> Mouse_IsButtonClick(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Mouse_State*&nbsp;</td><td class=\"PName last\">data,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">btn</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div></div>",384:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Direct access to keyboard</div></div>",611:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype611\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">enum</span> KEY_ID</div></div><div class=\"TTSummary\">Value coding a given physical key combining row number and key index in that row Can be KEY_1, KEY_SPACE, KEY_A, KEY_F1, etc.</div></div>",612:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype612\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">u8 Keyboard_Read(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">row</td></tr></table></td><td class=\"PAfterParameters\">) __FASTCALL</td></tr></table></div></div><div class=\"TTSummary\">Read keyboard matrix row</div></div>",613:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype613\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">void</span> Keyboard_Update()</div></div><div class=\"TTSummary\">Update all keyboard rows at once Only available when INPUT_KB_UPDATE is TRUE</div></div>",614:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype614\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> Keyboard_IsKeyPressed(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">key</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">When INPUT_KB_UPDATE is TRUE, this function use data retreived by Keyboard_Update() function Otherwise, the function read the key\'s row before checking the key.</div></div>",615:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype615\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> Keyboard_IsKeyPushed(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">key</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Check if a given key is just pushed Only available when INPUT_KB_UPDATE is TRUE</div></div>",389:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Advanced input manager</div></div>",390:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype390\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> IPM_Initialize(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">IPM_Config*&nbsp;</td><td class=\"PName last\">config</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Initialize input manager</div></div>",391:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype391\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline void</span> IPM_SetTimer(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">doubleClk,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">hold</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Initialize input manager</div></div>",392:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype392\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">void</span> IPM_Update()</div></div><div class=\"TTSummary\">Update device manager</div></div>",393:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype393\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> IPM_RegisterEvent(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">joy,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">input,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">event,</td></tr><tr><td class=\"PType first\">IPM_cb&nbsp;</td><td class=\"PName last\">cb</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Register a callback to a given device manager\'s event</div></div>",394:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype394\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 IPM_GetStatus(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">joy</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current device status</div></div>",395:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype395\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 IPM_GetStickDirection(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">joy</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current direction of the given device</div></div>",396:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype396\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 IPM_GetInputState(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">joy,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">in</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current device state</div></div>",397:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype397\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline</span> u8 IPM_GetInputTimer(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">joy,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">in</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get current device state timer</div></div>",398:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype398\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">const</span> c8* IPM_GetEventName(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">ev</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Get event name</div></div>"});