
/*
+-----------+-----------+
|                       
|                       
|                       
|     +--+     +--+     +
|     |  |     |  |     |
|     +--+     +--+     |
|                       |
+                       +
|                       |
|     +--+     +--+     |
|     |  |     |  |     |
|     +--+     +--+     |
|                       |
|                       |
|                       |
+-----------+-----------+
*/


#include "textures/texture_dentwall.h"
#include "textures/texture_redbricks.h"

signed char init_05[] = {
	5, 5, 0
};

/*
0-----------1-----------2
|                       
|                       
|                       
|     3--4     5--6     7
|     |  |     |  |     |
|     8--9    10--11    |
|                       |
12                     13
|                       |
|    14--15   16--17    |
|     |  |     |  |     |
|    18--19   20--21    |
|                       |
|                       |
|                       |
22----------23---------24
*/
signed char scene_05[] = {
    /* nbPoints = */ 25, /* nbWall = */ 24

, 0*6, 8*6	// 0
, 4*6, 8*6	// 1
, 8*6, 8*6	// 2
, 2*6, 6*6	// 3
, 3*6, 6*6  // 4
, 5*6, 6*6  // 5
, 6*6, 6*6  // 6
, 8*6, 6*6  // 7
, 2*6, 5*6  // 8
, 3*6, 5*6  // 9
, 5*6, 5*6  // 10
, 6*6, 5*6	// 11
, 0*6, 4*6	// 12
, 8*6, 4*6	// 13
, 2*6, 3*6	// 14
, 3*6, 3*6	// 15
, 5*6, 3*6	// 16
, 6*6, 3*6	// 17
, 2*6, 2*6	// 18
, 3*6, 2*6	// 19
, 5*6, 2*6	// 20
, 6*6, 2*6	// 21
, 0*6, 0*6	// 22
, 4*6, 0*6	// 23
, 8*6, 0*6	// 24

/*
0----w0-----1----w1-----2
|                       
w2                       
|                       
|     3w34     5w46     7
|     w5 w6   w7 w8    w9
|     8w109   10w1111   |
|                       |
12                     13
w12                     w13
|   14w1415  16w1517    |
|   w16 w17   w18w19    |
|   18w2019   20w2121   |
|                       |
|                       |
|                       |
22--w22------23----w23--24
*/
,  0,  1   // w0
,  1,  2  // w1
,  0, 12  // w2
,  3, 4   // w3
,  5, 6   // w4
,  3, 8   // w5
,  4,  9  // w6
,  5, 10  // w7
,  6, 11  // W8
,  7, 13  // w9
,  8, 9   // w10
, 10, 11  // w11
, 12, 22  // w12
, 13, 24  // w13
, 14, 15  // w14
, 16, 17  // w15
, 14, 18  // w16
, 15, 19  // w17
, 16, 20  // w18
, 17, 21  // w19
, 18, 19  // w20
, 20, 21  // w21
, 22, 23  // w22
, 23, 24  // w23
};

unsigned char *texture_05[]= {
	texture_dentwall		// W0
	, texture_dentwall		// W1
	, texture_dentwall		// W2
	, texture_redbricks		// W3
	, texture_redbricks		// W4
	, texture_redbricks		// W5
	, texture_redbricks		// W6
	, texture_redbricks		// W7
	, texture_redbricks		// W8
	, texture_dentwall		// W9
	, texture_redbricks		// W10
	, texture_redbricks		// W11
	, texture_dentwall		// W12
	, texture_dentwall		// W13
	, texture_redbricks		// W14
	, texture_redbricks		// W15
	, texture_redbricks		// W16
	, texture_redbricks		// W17
	, texture_redbricks		// W18
	, texture_redbricks		// W19
	, texture_redbricks		// W20
	, texture_redbricks		// W21
	, texture_dentwall		// W22
	, texture_dentwall		// W23

};

unsigned char win_05(signed char X, signed char Y) {
	return X >= 48;
}

