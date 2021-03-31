
// #include "textures/texture_dentwall.h"
// #include "textures/texture_redbricks.h"
#include "textures/texture_bluestone.h"
#include "textures/texture_redbrick.h"

signed char init_00[] = {
	0, 0, 0
};

// [ref scene_describe]
signed char scene_00[] = {

    /* nbPoints = */ 4, /* nbWall = */ 4
	, -6, -6	 	// P0
	, -6,  6		// P1
	,  6,  6		// P2
	,  6, -6		// P3
	, 0, 1   // W0
	, 1, 2   // W1
	, 2, 3   // W2
	, 3, 0   // W2

};

// [ref texture_file2buffer]
unsigned char *texture_00[]= {
	texture_bluestone		// W0
	, texture_redbrick		// W1
	, texture_bluestone		// W2
	, texture_redbrick			// W3
};

unsigned char win_00(signed char X, signed char Y) {
	return (X >= 5) && (Y >= 5);
}