

unsigned char running; // game state: 1 = Running, 0 = Leave.

unsigned char remaining_seconds;
unsigned char game_level; // 0: easy, 1: medium, 2: hard
unsigned char maze_completed; // 0: false, 1: true
unsigned char wanna_retry; // 0: false, 1: true
unsigned int current_score;

unsigned char idxTempoPing=0;
unsigned char tabTempoPing[]={250, 200, 150, 100, 50, 40, 30, 20, 10, 5, 4, 3, 2, 1};
unsigned char nxtPing;


unsigned char currentIdxParam;
//tabTempoPing[]={250, 200, 150, 100, 50, 40, 30, 20, 10, 5, 4, 3, 2, 1};
unsigned char tabLevelParam[] = {
// 5 
    255, 0,
    20*2, 8,
    20*1, 8, 
// 4
    255, 0,
    20*2, 8,
    20*1, 8, 
// 2
    255, 0,
    35*2, 4,
    35*1, 6, 
// 7
    255, 0,
    35*2, 4,
    35*1, 6, 
// 9
    255 , 0,
    90*2, 2,
    90*1, 4,
// 1
    255 , 0,
    90*2, 2,
    90*1, 4,
// 11
    255 , 0,
    90*2, 2,
    90*1, 4,
 };


void computeNewScore(){
    if (game_level == 0) {
        current_score += (tabLevelParam[currentIdxParam-2]-remaining_seconds) ;
    } else if (game_level == 1){
        current_score += 3*(tabLevelParam[currentIdxParam-2]-remaining_seconds) ;
    }else {
        current_score += 10*(tabLevelParam[currentIdxParam-2]-remaining_seconds) ;
    }
}
