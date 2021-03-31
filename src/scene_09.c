/*
+--------+--------+
|          *      |
+--+  +--------+  |
|     |           |
|  +  |  +--------+
|  |  |           |
|  +--+--+  +--+  |
|        |     |  |
|  +--+  +--+  +  |
|     |        |  |
+--+  +--+  +--+  |
|        |  |     |
+--------+  +-----+
*/

#include "textures/texture_bluestone.h"
#include "textures/texture_redbrick.h"

signed char init_09[] = {
	20, 32, 64
};



signed char scene_09[] = {
    /* nbPoints = */ 30, /* nbWall = */ 28

/*
  0--------1--------2
  |          *      |
  3--4  5--------6  |
  |     |           |
  |  7  |  8--------9
  |  |  |           |
  | 10--11-12 13-14 |
  |        |     |  |
  | 15-16 17-18 19  |
  |     |        |  |
 20-21 22-23 24--25 |
  |        |  |     |
 26-------27 28----29
*/
, 0*6, 6*6  // 0
, 3*6, 6*6  // 1
, 6*6, 6*6  // 2
, 0*6, 5*6  // 3
, 1*6, 5*6  // 4
, 2*6, 5*6  // 5
, 5*6, 5*6  // 6
, 1*6, 4*6  // 7
, 3*6, 4*6  // 8
, 6*6, 4*6  // 9
, 1*6, 3*6  // 10
, 2*6, 3*6  // 11
, 3*6, 3*6  // 12
, 4*6, 3*6  // 13
, 5*6, 3*6  // 14
, 1*6, 2*6  // 15
, 2*6, 2*6  // 16
, 3*6, 2*6  // 17
, 4*6, 2*6  // 18
, 5*6, 2*6  // 19
, 0*6, 1*6  // 20
, 1*6, 1*6  // 21
, 2*6, 1*6  // 22
, 3*6, 1*6  // 23
, 4*6, 1*6  // 24
, 5*6, 1*6  // 25
, 0*6, 0*6  // 26
, 3*6, 0*6  // 27
, 4*6, 0*6  // 28
, 6*6, 0*6  // 29
/*
  0---W0---1---w1---2
  w2          *     w3
  3w44  5--w5----6  |
 w6    w7           |
  |  7  |  8---w8---9
  | w9  |          w10
  |10w1111w1212 13w1314 |
  |       w14   w15 |
  |15w161617w171819 |
  |    w18      w19 |
20w202122w212324w2225|
 w23      w24w25    |
 26--w26--27 28-w27-29
*/
, 0, 1   // w0
, 1, 2   // w1
, 0, 3   // w2
, 2, 9   // w3
, 3, 4   // w4
, 5, 6   // w5
, 3, 20  // w6
, 5, 11  // w7
, 8, 9   // W8
, 7, 10  // w9
, 9, 29  // w10
, 10, 11 // w11
, 11, 12 // w12
, 13, 14 // w13
, 12, 17 // w14
, 14, 19 // w15
, 15, 16 // w16
, 17, 18 // w17
, 16, 22 // w18
, 19, 25 // w19
, 20, 21 // w20
, 22, 23 // w21
, 24, 25 // w22
, 20, 26 // w23
, 23, 27 // w24
, 24, 28 // w25
, 26, 27 // w26
, 28, 29 // w27
};

unsigned char *texture_09[]= {
      texture_bluestone      // W0
    , texture_bluestone      // W1
    , texture_redbrick       // W2
    , texture_redbrick       // W3
    , texture_bluestone      // W4
    , texture_bluestone      // W5
    , texture_redbrick       // W6
    , texture_redbrick       // W7
    , texture_bluestone      // W8
    , texture_redbrick       // W9
    , texture_bluestone      // W10
    , texture_bluestone      // W11
    , texture_bluestone      // W12
    , texture_bluestone      // W13
    , texture_redbrick       // W14
    , texture_redbrick       // W15
    , texture_bluestone      // W16
    , texture_bluestone      // W17
    , texture_redbrick       // W18
    , texture_redbrick       // W19
    , texture_bluestone      // W20
    , texture_bluestone      // w21
    , texture_bluestone      // w22
    , texture_redbrick       // w23
    , texture_redbrick       // w24
    , texture_redbrick       // w25
    , texture_bluestone      // w26
    , texture_bluestone      // w27
};

unsigned char win_09(signed char X, signed char Y) {
	return Y <= 0;
}
