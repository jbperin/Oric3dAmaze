#ifndef CONFIG_H
#define CONFIG_H

#include "constants.h"

#undef USE_SPRITE

#ifdef __GNUC__

#define     USE_C_DDA
#define     USE_C_PREDRAW
#define     USE_C_TOTO
#define     USE_C_DRAWWALLS
#define     USE_C_RAYCAST
#define     USE_C_VIEWPORT
#define     USE_C_PROCESS_POINT
#define     USE_C_ZBUFFWALLS
#define     USE_C_EXP
#define     USE_C_DISTOFFSETSLICES
#else

#undef     USE_C_DDA
#undef     USE_C_PREDRAW
#undef     USE_C_TOTO
#undef     USE_C_DRAWWALLS
#undef     USE_C_RAYCAST
#undef     USE_C_VIEWPORT
#undef     USE_C_PROCESS_POINT
#undef     USE_C_ZBUFFWALLS
#undef     USE_C_EXP
#undef     USE_C_DISTOFFSETSLICES
#define   USE_ASM_LOGTRIGO
#endif

#endif // CONFIG_H