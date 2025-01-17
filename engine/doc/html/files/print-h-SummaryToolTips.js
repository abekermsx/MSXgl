﻿NDSummary.OnToolTipsLoaded("File:print.h",{277:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Font initialization functions</div></div>",191:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype191\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">bool</span> Print_Initialize()</div></div><div class=\"TTSummary\">Initialize print module.&nbsp; Must be called after VDP_SetMode().</div></div>",716:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype716\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetMode(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">src</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Change current print mode.</div></div>",717:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype717\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetFont(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">u8*&nbsp;</td><td class=\"PName last\">font</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set the current font (and set mode to RAM).</div></div>",718:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype718\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> Print_SetBitmapFont(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">u8*&nbsp;</td><td class=\"PName last\">font</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Initialize print module and set a font in RAM.&nbsp; This function requires PRINT_USE_BITMAP to be set to TRUE.</div></div>",719:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype719\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetVRAMFont(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">u8*&nbsp;</td><td class=\"PName last\">font,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">UY&nbsp;</td><td class=\"PName last\">y,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">color</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set the current font and upload data to VRAM .&nbsp; This function requires PRINT_USE_VRAM to be set to TRUE.</div></div>",720:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype720\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetTextFont(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">u8*&nbsp;</td><td class=\"PName last\">font,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">offset</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Initialize print module and set a font in RAM.&nbsp; This function requires PRINT_USE_TEXT to be set to TRUE.</div></div>",721:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype721\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetSpriteFont(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">u8*&nbsp;</td><td class=\"PName last\">font,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">patIdx,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">sprtIdx</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set the current font and upload to Sprite Pattern Table.&nbsp; This function requires PRINT_USE_SPRITE to be set to TRUE.</div></div>",722:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype722\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">inline</span> u8 Print_GetSpritePattern()</div></div><div class=\"TTSummary\">Get pattern index of the 1st sprite character.&nbsp; This function requires PRINT_USE_SPRITE to be set to TRUE.</div></div>",723:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype723\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">inline</span> u8 Print_GetSpriteID()</div></div><div class=\"TTSummary\">Get the next sprite index.&nbsp; This function requires PRINT_USE_SPRITE to be set to TRUE.</div></div>",724:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype724\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">inline void</span> Print_SetSpriteID(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">id</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set the next sprite index.&nbsp; This function requires PRINT_USE_SPRITE to be set to TRUE.</div></div>",297:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Text draw functions</div></div>",298:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype298\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawChar(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">chr</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a single character</div></div>",299:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype299\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawCharX(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">c8&nbsp;</td><td class=\"PName last\">chr,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">num</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print the same character many times</div></div>",300:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype300\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawText(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">c8*&nbsp;</td><td class=\"PName last\">string</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a character string</div></div>",301:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype301\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawHex8(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">value</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a 8-bits binary value</div></div>",302:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype302\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawHex16(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u16&nbsp;</td><td class=\"PName last\">value</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a 16-bits hexadecimal value</div></div>",303:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype303\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawBin8(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">value</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a 8-bits binary value</div></div>",725:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype725\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawHex32(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u32&nbsp;</td><td class=\"PName last\">value</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a 32-bits hexadecimal value This function requires PRINT_USE_32B to be set to TRUE.</div></div>",726:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype726\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawInt(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">i32&nbsp;</td><td class=\"PName last\">value</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a 32-bits signed decimal value.&nbsp; This function requires PRINT_USE_32B to be set to TRUE.</div></div>",727:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype727\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawInt(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">i16&nbsp;</td><td class=\"PName last\">value</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a 16-bits signed decimal value.&nbsp; This function requires PRINT_USE_32B to be set to FALSE.</div></div>",728:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype728\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawFormat(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">c8*&nbsp;</td><td></td><td class=\"PName last\">format,</td></tr><tr><td class=\"first\"></td><td></td><td class=\"PSymbols\">...</td><td class=\"last\"></td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a formated string with a variable number of parameters.&nbsp; This function requires PRINT_USE_FORMAT to be set to TRUE.</div></div>",289:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype289\" class=\"NDPrototype\"><div class=\"PSection PPlainSection\"><span class=\"SHKeyword\">void</span> Print_Clear()</div></div><div class=\"TTSummary\">Clear screen</div></div>",290:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype290\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_Backspace(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">num</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Clear X character back from current cursor position</div></div>",291:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype291\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetColor(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">text,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">bg</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set the draw color</div></div>",731:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype731\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetColorShade(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">u8*&nbsp;</td><td class=\"PName last\">shade</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set color shade This function requires PRINT_COLOR_NUM to be set to reater than 1 value.</div></div>",732:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype732\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetShadow(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">bool</span>&nbsp;</td><td class=\"PName last\">enable,</td></tr><tr><td class=\"PType first\">i8&nbsp;</td><td class=\"PName last\">offsetX,</td></tr><tr><td class=\"PType first\">i8&nbsp;</td><td class=\"PName last\">offsetY,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">color</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set shadow effect This function requires PRINT_USE_FX_SHADOW to be set to TRUE.</div></div>",733:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype733\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_EnableShadow(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">bool</span>&nbsp;</td><td class=\"PName last\">enable</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Activate/desactivate shadow effect This function requires PRINT_USE_FX_SHADOW to be set to TRUE.</div></div>",734:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype734\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawTextShadow(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">c8*&nbsp;</td><td class=\"PName last\">string,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">i8&nbsp;</td><td class=\"PName last\">offsetX,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">i8&nbsp;</td><td class=\"PName last\">offsetY,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">u8&nbsp;</td><td class=\"PName last\">color</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Print a character string using shadow FX.&nbsp; This function requires PRINT_USE_2_PASS_FX and PRINT_USE_FX_SHADOW to be set to TRUE.</div></div>",735:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype735\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_SetOutline(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">bool</span>&nbsp;</td><td class=\"PName last\">enable,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">color</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Set shadow effect This function requires PRINT_USE_FX_OUTLINE to be set to TRUE.</div></div>",736:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype736\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_EnableOutline(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">bool</span>&nbsp;</td><td class=\"PName last\">enable</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Activate/desactivate shadow effect This function requires PRINT_USE_FX_OUTLINE to be set to TRUE.</div></div>",737:"<div class=\"NDToolTip TFunction LC\"><div class=\"TTSummary\">Print a character string using outline FX.&nbsp; This function requires PRINT_USE_2_PASS_FX and PRINT_USE_FX_OUTLINE to be set to TRUE.</div></div>",307:"<div class=\"NDToolTip TGroup LC\"><div class=\"TTSummary\">Boxes draw functions</div></div>",738:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype738\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawLineH(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">x,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">y,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">len</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Draw an horizontal line using characters This function requires PRINT_USE_GRAPH to be set to TRUE.</div></div>",739:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype739\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawLineV(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">x,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">y,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">len</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Draw a vertical line using characters This function requires PRINT_USE_GRAPH to be set to TRUE.</div></div>",740:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype740\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Print_DrawBox(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">x,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">y,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">width,</td></tr><tr><td class=\"PType first\">u8&nbsp;</td><td class=\"PName last\">height</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Draw a box using characters This function requires PRINT_USE_GRAPH to be set to TRUE.</div></div>"});