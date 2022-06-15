// ____________________________ 
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘
//  by Guillaume 'Aoineko' Blanchard under CC BY-SA license
//─────────────────────────────────────────────────────────────────────────────
#include "core.h"
#include "string.h"

// Table use to quick decimal-to-hexadecimal conversion
static const c8 g_HexChar[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

//
enum STRINT_PAD
{
	STRINT_PAD_NONE = 0,
	STRINT_PAD_ZERO,
	STRINT_PAD_SPACE,
};

//-----------------------------------------------------------------------------
// Group: String

//-----------------------------------------------------------------------------
// Function: String_Format
// Build a zero-terminated string
//
// Parameters:
//   dest - Destination string buffer (must big enough to contain the whole string)
//   format - Formating string
//   ... - Variable number of parameter (depends on the Formating string)
void String_Format(c8* dest, const c8* format, ...)
{
	va_list args;
	va_start(args, format);

	c8 str[16];
	const c8* ptr = format;
	while(*ptr != 0)
	{
		if(*ptr == '%')
		{
			ptr++;
			
			// Parse length
			u8 pad = STRINT_PAD_NONE;
			u8 len = 0;
			if(*ptr == '0')
			{
				pad = STRINT_PAD_ZERO;
				ptr++;
			}
			else if((*ptr >= '1') && (*ptr <= '9'))
			{
				pad = STRINT_PAD_SPACE;
				len = *ptr - '0';
				ptr++;
			}
			while((*ptr >= '0') && (*ptr <= '9'))
			{
				len *= 10;
				len += *ptr - '0';
				ptr++;
			}
			
			// Parse variable types
			switch(*ptr)
			{
				case '%':
					*dest++ = '%';
					break;

				// Signed integer decimal
				#if (STRING_USE_INT32)
				case 'I':
				case 'D':
				#endif
				case 'i':
				case 'd':
				{
					#if (STRING_USE_INT32)
					i32 val;
					if((*ptr == 'I') || (*ptr == 'D'))
						val = (i32)va_arg(args, i32);
					else
						val = (i32)va_arg(args, i16);
					#else
					i16 val = (i16)va_arg(args, i16);
					#endif
					// Sign
					if(val < 0)
					{
						*dest++ = '-';
						val = -val;
					}
					// Build number string
					c8* ptr = str;
					*ptr = 0;
					u8 digit = 1;
					while(val >= 10)
					{
						*++ptr = '0' + (val % 10);
						val /= 10;
						digit++;
					}
					*++ptr = '0' + val;
					// Padding
					if(len > digit)
					{
						c8 padChr = (pad == STRINT_PAD_ZERO) ? '0' : ' ';
						for(u8 i = 0; i < len - digit; ++i)
							*dest++ = padChr;
					}
					// Copy digit string
					while(*ptr != 0)
						*dest++ = *ptr--;
					break;
				}				

				// Unsigned integer decimal
				#if (STRING_USE_INT32)
				case 'U':
				#endif
				case 'u':
					break;

				// Hexadecimal 32-bits integer
				#if (STRING_USE_INT32)
				case 'X':
				{
					if(len == 0)
						len = 8;
					u32 val = (u32)va_arg(args, u32);
					// Print_DrawHex32(val);
					if(len > 7)
						*dest++ = g_HexChar[(val >> 28) & 0xF];
					if(len > 6)
						*dest++ = g_HexChar[(val >> 24) & 0xF];
					if(len > 5)
						*dest++ = g_HexChar[(val >> 20) & 0xF];
					if(len > 4)
						*dest++ = g_HexChar[(val >> 16) & 0xF];
					if(len > 3)
						*dest++ = g_HexChar[(val >> 12) & 0xF];
					if(len > 2)
						*dest++ = g_HexChar[(val >> 8) & 0xF];
					if(len > 1)
						*dest++ = g_HexChar[(val >> 4) & 0xF];
					*dest++ = g_HexChar[val & 0xF];
					break;
				}
				#endif

				// Hexadecimal 16-bits integer
				case 'x':
				{
					if(len == 0)
						len = 4;
					u16 val = (u16)va_arg(args, u16);
					if(len > 3)
						*dest++ = g_HexChar[(val >> 12) & 0xF];
					if(len > 2)
						*dest++ = g_HexChar[(val >> 8) & 0xF];
					if(len > 1)
						*dest++ = g_HexChar[(val >> 4) & 0xF];
					*dest++ = g_HexChar[val & 0xF];
					break;
				}

				// Character
				case 'c':
				{
					c8 val = (c8)va_arg(args, c8);
					*dest++ = val;
					break;
				}

				// String
				case 's':
				{
					const c8* val = (const c8*)va_arg(args, const c8*);
					u8 len = String_Length(val);
					for(u8 i = 0; i < len; i++)
						*dest++ = *val++;
					break;
				}
			}
		}
		else
			*dest++ = *ptr;
		
		ptr++;
	}
	*dest = 0;

	va_end(args);
}