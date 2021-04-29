
/*
+--+-----+  +-----+
|  |        |     |
|  +  +  +--+  +  |
|     |        |  |
|  +--+-----+--+  |
|           |     |
+-----+  +  |  +--+
|     |  | *|  |  |
|  +--+  |  +  |  |
|  |     |     |  |
|  +  +--+  +--+  |
|        |        |
+--------+--------+
*/


#include "textures/texture_bluestone.h"
#include "textures/texture_redbrick.h"
#include "textures/texture_dentwall.h"
signed char init_07[] = {
	20, 14, 0
};



signed char scene_07[] = {
    /* nbPoints = */ 30, /* nbWall = */ 28
/*
  0--1-----2  3-----4
  |  |        |     |
  |  5  6  7--8  9  |
  |     |        |  |
  | 10-11----12--13 |
  |           |     |
 14----15  16 |  17-18
  |     |  | *|  |  |
  | 19-20  |  21 |  |
  |  |     |     |  |
  | 22 23--24 25-26 |
  |        |        |
 27-------28-------29
*/
, 0*6, 6*6 // 0
, 1*6, 6*6 // 1
, 3*6, 6*6 // 2
, 4*6, 6*6 // 3
, 6*6, 6*6 // 4
, 1*6, 5*6 // 5
, 2*6, 5*6 // 6
, 3*6, 5*6 // 7
, 4*6, 5*6 // 8
, 5*6, 5*6 // 9
, 1*6, 4*6 // 10
, 2*6, 4*6 // 11
, 4*6, 4*6 // 12
, 5*6, 4*6 // 13
, 0*6, 3*6 // 14
, 2*6, 3*6 // 15
, 3*6, 3*6 // 16
, 5*6, 3*6 // 17
, 6*6, 3*6 // 18
, 1*6, 2*6 // 19
, 2*6, 2*6 // 20
, 4*6, 2*6 // 21
, 1*6, 1*6 // 22
, 2*6, 1*6 // 23
, 3*6, 1*6 // 24
, 4*6, 1*6 // 25
, 5*6, 1*6 // 26
, 0*6, 0*6 // 27
, 3*6, 0*6 // 28
, 6*6, 0*6 // 29

/*
  0w01-w1--2  3-w2--4
  w3 w4      w5    w6
  |  5  6  7w78  9  |
  |    w8       w9  |
  |10w1011w1112w1213|
  |          w13    |
 14w14-15  16 | 17w1518
  w16  w17w18*| w19 w20
  |19w2120 |  21 |  |
  |  w22   |     |  |
  | 2223w232425w2426|
  |       w25       |
 27-w26---28---w27-29
*/
, 0, 1   // w0
, 1, 2   // w1
, 3, 4   // w2
, 0, 14  // w3
, 1, 5   // w4
, 3, 8   // w5
, 4, 18  // w6
, 7, 8   // w7
, 6, 11  // W8
, 9, 13  // w9
, 10, 11 // w10
, 11, 12 // w11
, 12, 13 // w12
, 12, 21 // w13
, 14, 15 // w14
, 17, 18 // w15
, 14, 27 // w16
, 15, 20 // w17
, 16, 24 // w18
, 17, 26 // w19
, 18, 29 // w20
, 19, 20 // w21
, 19, 22 // w22
, 23, 24 // w23
, 25, 26 // w24
, 24, 28 // w25
, 27, 28 // w26
, 28, 29 // w27
};

unsigned char *texture_07[]= {
        texture_dentwall    // W0
    , texture_dentwall    // W1
    , texture_dentwall    // W2
    , texture_dentwall     // W3
    , texture_redbrick     // W4
    , texture_redbrick     // W5
    , texture_dentwall     // W6
    , texture_bluestone    // W7
    , texture_redbrick     // W8
    , texture_redbrick     // W9
    , texture_bluestone    // W10
    , texture_bluestone    // W11
    , texture_bluestone    // W12
    , texture_redbrick     // W13
    , texture_bluestone    // W14
    , texture_bluestone    // W15
    , texture_dentwall     // W16
    , texture_redbrick     // W17
    , texture_redbrick     // W18
    , texture_redbrick     // W19
    , texture_dentwall     // W20
    , texture_bluestone    // w21
    , texture_redbrick     // w22
    , texture_bluestone    // w23
    , texture_bluestone    // w24
    , texture_redbrick     // w25
    , texture_dentwall    // w26
    , texture_dentwall    // w27
};

unsigned char win_07(signed char X, signed char Y) {
	return Y >= 36;
}