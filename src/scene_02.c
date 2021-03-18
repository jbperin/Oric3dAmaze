/*
+--------+-----+
|        |   X |
|  +  +--+  +--+
|  |           |
|  +-----+  +--+
|  |     |  |  |
+  |  +  +  +  |
|  |  |        |
|  +--+--------+
|               
+-----+--------+
*/

/*
0--------1-----2
|        |   X |
|  3  4--5  6--7
|  |           |
|  8-----9 10-11
|  |     |  |  |
12 | 13 14 15  |
|  |  |        |
| 16-17-------18
|               
19---20-------21
*/
#include "texture_map02.h"
#include "textures/texture_bluestone.h"
#include "textures/texture_redbrick.h"

signed char init_02[] = {
	27, 27, 0
};

signed char scene_02[] = {
    /* nbPoints = */ 22, /* nbWall = */ 21
, 0*6, 5*6	// 0
, 3*6, 5*6	// 1
, 5*6, 5*6	// 2
, 1*6, 4*6	// 3
, 2*6, 4*6  // 4
, 3*6, 4*6  // 5
, 4*6, 4*6  // 6
, 5*6, 4*6  // 7
, 1*6, 3*6  // 8
, 3*6, 3*6  // 9
, 4*6, 3*6  // 10
, 5*6, 3*6	// 11
, 0*6, 2*6	// 12
, 2*6, 2*6	// 13
, 3*6, 2*6	// 14
, 4*6, 2*6	// 15
, 1*6, 1*6	// 16
, 2*6, 1*6	// 17
, 5*6, 1*6	// 18
, 0*6, 0*6	// 19
, 2*6, 0*6	// 20
, 5*6, 0*6	// 21

/*
  0---w0---1-w1--2
 w2       w3   Xw4
  |  3  4w55  6w67
  | w7          w8
  |  8--w9-9 10w1011
  | w11   w12w13 w14
  12 | 13 14 15  |
 w15 | w16       |
  |16w1717--W18--18
  |               
  19w1920--w20--21
*/
,  0,  1   // w0
,  1,  2  // w1
,  0, 12  // w2
,  1, 5   // w3
,  2, 7   // w4
,  4, 5   // w5
,  6,  7  // w6
,  3,  8  // w7
,  7, 11  // W8
,  8, 9   // w9
, 10, 11  // w10
,  8, 16  // w11
,  9, 14  // w12
, 10, 15  // w13
, 11, 18  // w14
, 12, 19  // w15
, 13, 17  // w16
, 16, 17  // w17
, 17, 18  // w18
, 19, 20  // w19
, 20, 21  // w20
};


unsigned char *texture_02[]= {
	texture_bluestone		// W0
	, texture_redbrick		// W1
	, texture_bluestone		// W2
	, texture_redbrick		// W3
	, texture_map02		// W4
	, texture_bluestone		// W5
	, texture_bluestone		// W6
	, texture_redbrick		// W7
	, texture_redbrick		// W8
	, texture_bluestone		// W9
	, texture_bluestone		// W10
	, texture_redbrick		// W11
	, texture_redbrick		// W12
	, texture_bluestone		// W13
	, texture_bluestone		// W14
	, texture_bluestone		// W15
	, texture_bluestone		// W16
	, texture_redbrick		// W17
	, texture_redbrick		// W18
	, texture_bluestone		// W19
	, texture_bluestone		// W20

};

unsigned char win_02(signed char X, signed char Y) {
	return X >= 30;
}
unsigned char collision_02(signed char X, signed char Y) {
	if (X%6 == 0) {
		if (Y%6 == 0) {
			// X and Y on 6 *6 grid
			return 0;
		} else {
			// X on grid, Y not on grid
			if (X == 0) {
				return 0;
			} else if (X == 6) {
				return (Y < 6) || (Y > 24);
			} else if (X == 12) {
				return (
					(Y < 6) || (Y > 12)
				);
			} else if (X == 18) {
				return ( (Y < 12) || ((Y > 18) && (Y < 24)) );
			} else if (X == 24) {
				return((Y<12) 
				|| (Y > 18));
			} else if (X == 30){
				return (Y < 6);
			} else {
				return 1;
			}
		}
	} else if (Y%6 == 0) {
		if (Y == 0) {
			return 0;
		} else if (Y == 6) {
			return (X < 6);
		} else if (Y == 12) {
			return 1;
		} else if (Y == 18) {
			return ( (X < 6) || ( (X > 18) && (X < 24) ));
		} else if (Y == 24) {
			return ((X < 12) || ((X > 18) && (X < 24)));
		} else if (Y == 30) {
			return 0;
		} else {
			return 1;
		}
	}
    return 1;
}
