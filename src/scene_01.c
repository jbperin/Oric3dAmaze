/*
+--------+-----+--------+
|        |     |        |
|  +-----+--+  |  +  +  |
|        |  |  |  |  |  |
|  +--+  |  |  |  |  |  |
|     |  |  |  |  |  |  |
+--+  |  |  +  +--+  |  +
|     |  |           |  |
|     |  +--+     +--+  |
|     |     |     |     |
+-----+     +--+--+  +--+
|              |     |  |
|  +--------+  |  +--+  |
|           |  |  |     |
|     +     +--+  +     |
|     |                 |
+-----+-----+-----------+


0--------1-----2--------3
|        |     |        |
|  4-----5--6  |  7  8  |
|        |  |  |  |  |  |
|  9-10  |  |  |  |  |  |
|     |  |  |  |  |  |  |
11-12 |  | 13 14-15  | 16
|     |  |           |  |
|     | 17-18    19-20  |
|     |     |     |     |
21---22    23-24-25 26-27
|              |     |  |
|  28------29  | 30-31  |
|           |  |  |     |
|    32    33-34 35     |
|     |                 |
36---37----38----------39
*/

#include "textures/texture_bluestone.h"
#include "textures/texture_redbrick.h"

#include "texture_map01.h"

signed char init_01[] = {
	12, 45, 0
};
signed char scene_01[] = {
    /* nbPoints = */ 40, /* nbWall = */ 39
, 0*6, 8*6	// 0
, 3*6, 8*6	// 1
, 5*6, 8*6	// 2
, 8*6, 8*6	// 3
, 1*6, 7*6  // 4
, 3*6, 7*6  // 5
, 4*6, 7*6  // 6
, 6*6, 7*6  // 7
, 7*6, 7*6  // 8
, 1*6, 6*6  // 9
, 2*6, 6*6  // 10
, 0*6, 5*6	// 11
, 1*6, 5*6	// 12
, 4*6, 5*6	// 13
, 5*6, 5*6	// 14
, 6*6, 5*6	// 15
, 8*6, 5*6	// 16
, 3*6, 4*6	// 17
, 4*6, 4*6	// 18
, 6*6, 4*6	// 19
, 7*6, 4*6	// 20
, 0*6, 3*6	// 21
, 2*6, 3*6	// 22
, 4*6, 3*6	// 23
, 5*6, 3*6	// 24
, 6*6, 3*6	// 25
, 7*6, 3*6	// 26
, 8*6, 3*6	// 27
, 1*6, 2*6	// 28
, 4*6, 2*6	// 29
, 6*6, 2*6	// 30
, 7*6, 2*6	// 31
, 2*6, 1*6	// 32
, 4*6, 1*6	// 33
, 5*6, 1*6	// 34
, 6*6, 1*6	// 35
, 0*6, 0*6	// 36
, 2*6, 0*6	// 37
, 4*6, 0*6	// 38
, 8*6, 0*6	// 39

/*
 0--w0----1--w1-2---w2---3
 |       w4    w5        |
 |  4--w7-5w86  |  7  8  |
 w3      w9 w10 | w11w12w6
 | 9w1310 |  |  |  |  |  |
 |    w14 |  |  |  |  |  |
11w1512|  | 13 14w1615| 16
w17    |  |           | w18
 |     | 17w1918 19w2020 |
 |     |    w21   w22    |
 21w2322  23w2424w252526w2627
w27            w28   w29 w30
 |  28--w31--29 | 30w3231|
 |         w33  | w34    |
 |    32   33w3534 35    |
 |    w36                |
36w3737-w38--38---w39---39
*/
,  0,  1	// w0
//,  1,  2	// w1
,  2,  3  // w2
,  0, 11  // w3
,  1,  5  // w4
,  2, 14  // w5
,  3, 16  // w6
,  4,  5  // w7
,  5,  6  // W8
,  5, 17  // w9
,  6, 13  // w10
,  7, 15  // w11
,  8, 20  // w12
,  9, 10  // w13
, 10, 22  // w14
, 11, 12  // w15
, 14, 15  // w16
, 11, 21  // w17
, 16, 27  // w18
, 17, 18  // w19
, 19, 20  // w20
, 18, 23  // w21
, 19, 25  // w22
, 21, 22  // w23
, 23, 24  // w24
, 24, 25  // w25
, 26, 27  // w26
, 21, 36  // w27
, 24, 34  // w28
, 26, 31  // w29
, 27, 39  // w30
, 28, 29  // w31
, 30, 31  // w32
, 29, 33  // w33
, 30, 35  // w34
, 33, 34  // w35
, 32, 37  // w36
, 36, 37  // W37
, 37, 38  // w38
, 38, 39  // w39
};

// [ref texture_file2buffer]
unsigned char *texture_01[]= {
	texture_bluestone		// W0
//	, texture_christmas		// W1
	, texture_bluestone		// W2
	, texture_bluestone		// W3
	, texture_map01		// W4
	, texture_bluestone		// W5
	, texture_bluestone		// W6
	, texture_bluestone		// W7
	, texture_bluestone		// W8
	, texture_bluestone		// W9
	, texture_bluestone		// W10
	, texture_bluestone		// W11
	, texture_bluestone		// W12
	, texture_bluestone		// W13
	, texture_bluestone		// W14
	, texture_bluestone		// W15
	, texture_bluestone		// W16
	, texture_bluestone		// W17
	, texture_bluestone		// W18
	, texture_bluestone		// W19
	, texture_bluestone		// W20
	, texture_bluestone		// W21
	, texture_redbrick		// W22
	, texture_redbrick		// W23
	, texture_redbrick		// W24
	, texture_redbrick		// W25
	, texture_redbrick		// W26
	, texture_redbrick		// W27
	, texture_redbrick		// W28
	, texture_redbrick		// W29
	, texture_redbrick		// W30
	, texture_redbrick		// W31
	, texture_redbrick		// W32
	, texture_redbrick		// W33
	, texture_redbrick		// W34
	, texture_redbrick		// W35
	, texture_redbrick		// W36
	, texture_redbrick		// W37
	, texture_redbrick		// W38
	, texture_redbrick		// W39
};

unsigned char win_01(signed char X, signed char Y) {
	return Y >= 48;
}
unsigned char collision_01(signed char X, signed char Y) {
	if (X%6 == 0) {
		if (Y%6 == 0) {
			// X and Y on 6 *6 grid
			return (
				( 	(X == 6) && ((Y == 6) || (Y == 24)) )
				|| ((X ==18) && ((Y == 6) || (Y == 18)) )
				|| ((X ==36) && ((Y ==24)) )
				|| ((X ==42) && ((Y == 6)) )
			);
		} else {
			// X on grid, Y not on grid
			if (X == 0) {
				return 0;
			} else if (X == 6) {
				return 1;
			} else if (X == 12) {
				return (
					((Y>6) && (Y<18)) || (Y > 36)
				);
			} else if (X == 18) {
				return ((Y < 24) ||(Y > 48));
			} else if (X == 24) {
				return((Y<6) 
				|| ((Y>12) && (Y<18)) 
				|| ((Y > 24) &&  (Y < 30)) 
				|| (Y > 42));
			} else if (X == 30) {
				return((Y<6) 
				|| ((Y>18) && (Y<30)));
			} else if (X == 36) {
				return((Y<6) 
				|| ((Y>12) && (Y<18)) 
				|| ((Y > 24) &&  (Y < 30)) 
				|| (Y > 42));
			} else if (X == 42) {
				return((Y<12) 
				|| ((Y>18) && (Y<24)) 
				|| (Y > 42));
			} else if (X == 48) {
				return 0;
			} else {
				return 1;
			}
		}
	} else if (Y%6 == 0) {
		if (Y == 0) {
			return 0;
		} else if (Y == 6) {
			return ((X < 24) || (X > 30));
		} else if (Y == 12) {
			return ((X < 6) || ((X > 24) && (X <36)) || (X > 42));
		} else if (Y == 18) {
			return (( (X > 12) && (X<24)) || ( (X > 36) && (X < 42)));
		} else if (Y == 24) {
			return ((X < 18) || ((X > 24) && (X < 36)) || (X > 42));
		} else if (Y == 30) {
			return (((X > 6) && (X < 30)) || (X > 36));
		} else if (Y == 36) {
			return ((X < 6 ) || (X > 12));
		} else if (Y == 42) {
			return ((X < 6 ) || (X > 24));
		} else if (Y == 48) {
			return ((X > 18 ) && (X < 30));
		} else {
			return 1;
		}

	}
    return 1;
   	//return (Y < 48);

}