

unsigned char running; // game state: 1 = Running, 0 = Leave.

unsigned char remaining_seconds;

unsigned char game_level; // 0: easy 1: médium 2: hard

unsigned char maze_completed; // 0: false, 1: true
unsigned char wanna_retry; // 0: false, 1: true


unsigned char idxTempoPing=0;
unsigned char tabTempoPing[]={250, 200, 150, 100, 50, 10, 5, 4, 3, 2, 1};
unsigned char nxtPing;

