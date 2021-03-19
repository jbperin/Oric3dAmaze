
/*
  +  +--+--+
  |  |  |  |
  |  |  +  |
  |  |     |
  |  +--+  |
  |        |
  +--------+
*/

/*
  0  1--2--3
  |  |  |  |
  |  |  4  |
  |  |     |
  |  5--6  |
  |        |
  7--------8
*/

#include "textures/texture_greystone.h"
#include "textures/texture_bluestone.h"
// #include "textures/texture_redbrick.h"

signed char init_04[] = {
	9, 12, 64
};

signed char scene_04[] = {
    /* nbPoints = */ 9, /* nbWall = */ 8
, 0*6, 3*6	// 0
, 1*6, 3*6	// 1
, 2*6, 3*6	// 2
, 3*6, 3*6	// 3
, 2*6, 2*6  // 4
, 1*6, 1*6  // 5
, 2*6, 1*6  // 6
, 0*6, 0*6  // 7
, 3*6, 0*6  // 8

/*
  0  1w02w13
 w2 w3 w4 w5
  |  |  4  |
  |  |     |
  |  5w66  |
  |        |
  7---w7---8
*/

,  1, 2   // w0
,  2, 3  // w1
,  0, 7  // w2
,  1, 5   // w3
,  2, 4   // w4
,  3, 8   // w5
,  5, 6  // w6
,  7, 8  // w7
};


unsigned char *texture_04[]= {
	texture_bluestone		// W0
	, texture_bluestone		// W1
	, texture_greystone		// W2
	, texture_greystone		// W3
	, texture_greystone		// W4
	, texture_greystone		// W5
	, texture_bluestone		// W6
	, texture_bluestone		// W7


};

unsigned char win_04(signed char X, signed char Y) {
	return Y >= 18;
}
// unsigned char collision_04(signed char X, signed char Y) {
// 	if (X%6 == 0) {
// 		if (Y%6 == 0) {
// 			// X and Y on 6 *6 grid
// 			return 0;
// 		} else {
// 			// X on grid, Y not on grid
// 			if (X == 0) {
// 				return 0;
// 			} else if (X == 6) {
// 				return (Y < 6);
// 			} else if (X == 12) {
// 				return (Y < 12);
// 			} else if (X == 18) {
// 				return 0;
// 			} else {
// 				return 1;
// 			}
// 		}
// 	} else if (Y%6 == 0) {
// 		if (Y == 0) {
// 			return 0;
// 		} else if (Y == 6) {
// 			return (X < 6) || (X > 12);
// 		} else if (Y == 12) {
// 			return 1;
// 		} else if (Y == 18) {
// 			return (X < 6);
// 		} else {
// 			return 1;
// 		}
// 	}
//     return 1;
// }
