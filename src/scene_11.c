/*
+--------------+-----------+
|              |           |
|  +--------+  +--+  +--+  |
|           |     |   * |  |
|           |     +-----+  |
|           |           |  |
+-----+     +-----+--+  |  |
|     |           |     |  |
|  +--+--------+  |  +--+  |
|  |           |  |        |
|  +--+  +--+  +  +-----+  |
|     |     |     |        |
+--+  +--+  +-----+--+  +--+
   |     |           |  |  |
+  |     +  +--+--+  |  +  |
|  |     |     |     |     |
|  +     +-----+  +--+--+  |
|                 |        |
+-----------------+--------+
*/

#include "textures/texture_bluestone.h"
#include "textures/texture_claybricks.h"
#include "textures/texture_greystone.h"

signed char init_11[] = {
	44, 44, 64
};



signed char scene_11[] = {
    /* nbPoints = */ 52, /* nbWall = */ 51

/*

  0--------------1-----------2
  |              |           |
  |  3--------4  5--6  7--8  |
  |           |     |   * |  |
  |           |     9----10  |
  |           |           |  |
  11---12     13---14-15  |  |
  |     |           |     |  |
  |  16-17------18  | 19-20  |
  |  |           |  |        |
  |  21-22 23-24 25 26---27  |
  |     |     |     |        |
 28-29 30-31 32----33-34 35-36
     |     |           |  |  |
 37  |    38 39-40-41  | 42  |
  |  |     |     |     |     |
  | 43    44----45 46-47-48  |
  |                 |        |
 49----------------50-------51
  
*/
, 0*6, 9*6  // 0
, 5*6, 9*6  // 1
, 9*6, 9*6  // 2
, 1*6, 8*6  // 3
, 4*6, 8*6  // 4
, 5*6, 8*6  // 5
, 6*6, 8*6  // 6
, 7*6, 8*6  // 7
, 8*6, 8*6  // 8
, 6*6, 7*6  // 9
, 8*6, 7*6  // 10
, 0*6, 6*6  // 11
, 2*6, 6*6  // 12
, 4*6, 6*6  // 13
, 6*6, 6*6  // 14
, 7*6, 6*6  // 15
, 1*6, 5*6  // 16
, 2*6, 5*6  // 17
, 5*6, 5*6  // 18
, 7*6, 5*6  // 19
, 8*6, 5*6  // 20
, 1*6, 4*6  // 21
, 2*6, 4*6  // 22
, 3*6, 4*6  // 23
, 4*6, 4*6  // 24
, 5*6, 4*6  // 25
, 6*6, 4*6  // 26
, 8*6, 4*6  // 27
, 0*6, 3*6  // 28
, 1*6, 3*6  // 29
, 2*6, 3*6  // 30
, 3*6, 3*6  // 31
, 4*6, 3*6  // 32
, 6*6, 3*6  // 33
, 7*6, 3*6  // 34
, 8*6, 3*6  // 35
, 9*6, 3*6  // 36
, 0*6, 2*6  // 37
, 3*6, 2*6  // 38
, 4*6, 2*6  // 39
, 5*6, 2*6  // 40
, 6*6, 2*6  // 41
, 8*6, 2*6  // 42
, 1*6, 1*6  // 43
, 3*6, 1*6  // 44
, 5*6, 1*6  // 45
, 6*6, 1*6  // 46
, 7*6, 1*6  // 47
, 8*6, 1*6  // 48
, 0*6, 0*6  // 49
, 6*6, 0*6  // 50
, 9*6, 0*6  // 51

/*
  0----w0--------1---w1------2
  w2            w3          w4
  |  3--w5----4  5w66  7w78  |
  |          w8    w9   *w10 |
  |           |     9-w1110  |
  |           |         w12  |
  11w1312    13w1414w1515 |  |
 w16   w17        w18     |  |
  |16w1917--w20-18  |19w2120 |
  | w22         w23 |        |
  |21w242223w252425 26w2627  |
  |    w27  w28   w29        |
28w302930w313132w3233w333435w3436
    w35   w36         w37w38w39
 37  |    3839w4040w4141|42  |
 w42 |    w43   w44    |     |
  | 43    44w45-4546w4647w4748|
  |                w48       |
 49----w49---------50---w50-51

*/

,  0, 1 // w0
,  1, 2 // w1
,  0,11 // w2
,  1, 5 // w3
,  2,36 // w4
,  3, 4 // w5
,  5, 6 // w6
,  7, 8 // w7
,  4,13 // w8
,  6, 9 // w9
,  8,10 // w10
,  9,10 // w11
, 10,20 // w12
, 11,12 // w13
, 13,14 // w14
, 14,15 // w15
, 11,28 // w16
, 12,17 // w17
, 14,26 // w18
, 16,17 // w19
, 17,18 // w20
, 19,20 // w21
, 16,21 // w22
, 18,25 // w23
, 21,22 // w24
, 23,24 // w25
, 26,27 // w26
, 22,30 // w27
, 24,32 // w28
, 26,33 // w29
, 28,29 // w30
, 30,31 // w31
, 32,33 // w32
, 33,34 // w33
, 35,36 // w34
, 29,43 // w35
, 31,38 // w36
, 34,47 // w37
, 35,42 // w38
, 36,51 // w39
, 39,40 // w40
, 40,41 // w41
, 37,49 // w42
, 38,44 // w43
, 40,45 // w44
, 44,45 // w45
, 46,47 // w46
, 47,48 // w47
, 46,50 // w48
, 49,50 // w49
, 50,51 // w50
};

unsigned char *texture_11[]= {
      texture_greystone    // W0
    , texture_greystone    // W1
    , texture_greystone    // W2
    , texture_claybricks    // W3
    , texture_greystone    // W4
    , texture_bluestone    // W5
    , texture_bluestone    // W6
    , texture_bluestone    // W7
    , texture_claybricks    // W8
    , texture_claybricks    // W9
    , texture_claybricks    // W10
    , texture_bluestone    // W11
    , texture_claybricks    // W12
    , texture_bluestone    // W13
    , texture_bluestone    // W14
    , texture_bluestone    // W15
    , texture_claybricks    // W16
    , texture_claybricks    // W17
    , texture_claybricks    // W18
    , texture_bluestone    // W19
    , texture_bluestone    // W20
    , texture_bluestone    // W21
    , texture_claybricks    // W22
    , texture_claybricks    // W23
    , texture_bluestone    // W24
    , texture_bluestone    // W25
    , texture_bluestone    // W26
    , texture_claybricks    // W27
    , texture_claybricks    // W28
    , texture_claybricks    // W29
    , texture_claybricks    // W20
    , texture_claybricks    // W21
    , texture_claybricks    // W22
    , texture_claybricks    // W23
    , texture_claybricks    // W24
    , texture_claybricks    // W25
    , texture_claybricks    // W26
    , texture_claybricks    // W27
    , texture_claybricks    // W28
    , texture_claybricks    // W29
    , texture_bluestone    // W30
    , texture_bluestone    // W31
    , texture_bluestone    // W32
    , texture_bluestone    // W33
    , texture_bluestone    // W34
    , texture_claybricks    // W35
    , texture_claybricks    // W36
    , texture_claybricks    // W37
    , texture_claybricks    // W38
    , texture_greystone    // W39
    , texture_bluestone    // W40
    , texture_bluestone    // W41
    , texture_greystone    // W42
    , texture_claybricks    // W43
    , texture_claybricks    // W44
    , texture_bluestone    // W45
    , texture_bluestone    // W46
    , texture_bluestone    // W47
    , texture_claybricks    // W48
    , texture_greystone    // W49
    , texture_greystone    // W50

};

unsigned char win_11(signed char X, signed char Y) {
	return X <= 0;
}