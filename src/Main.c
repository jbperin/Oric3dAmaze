// Author : Jean-Baptiste PERIN
// Date : 2021
//
// Build with OSDK: osdk_build.bat && osdk_execute.bat
//

#undef DEBUG

#include "lib.h"

#include "config.h"




#include "raycast.c"
#include "scene.c"

#include "game.c"

#include "player.c"

#include "texel.c"

#include "drawWalls.c"


extern unsigned char 	kernel_cs;
extern unsigned char 	kernel_s;

extern unsigned char 	kernel_fraction;
extern unsigned char 	kernel_beat;
extern unsigned char 	kernel_tempo;
extern unsigned char 	nbE_keybuf;

char message [40];
unsigned char refreshNeeded;
unsigned char running ;
int mode0;

#define CHANGE_INK_TO_BLACK             0
#define CHANGE_INK_TO_RED	            1		
#define CHANGE_INK_TO_GREEN	            2		
#define CHANGE_INK_TO_BLUE	            4		
#define CHANGE_PAPER_TO_WHITE	        23

#include "mmi_fr.c"

void prepareRGB(){
    int ii;

    // parcours de lignes de 3 en 3
    for (ii=0; ii < (TEXT_SCREEN_HEIGHT - NB_LESS_LINES_4_COLOR)*8;  ii+=3){
        poke (HIRES_SCREEN_ADDRESS+((ii)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_RED);
        poke (HIRES_SCREEN_ADDRESS+((ii+1)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_GREEN);
        poke (HIRES_SCREEN_ADDRESS+((ii+2)*NEXT_SCANLINE_INCREMENT),CHANGE_INK_TO_BLUE);
    }
}


// [ref camera_situation]
void initCamera(signed char init[] ){
    rayCamPosX               = init[0]; // 25; // 12;
    rayCamPosY               = init[1]; // 25; // 46; 
    rayCamRotZ               = init[2]; //-128; // 32;
    RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;
}


void keyPressed(unsigned char c){
	// printf ("kp: %x, ", c);
    if (c == keyForward) {
            forward(); 
            refreshNeeded   = 1;
    } else if (c == keyBackward) {
            backward();
            refreshNeeded   = 1;
    } else if (c == keyTurnLeft) {
            rayCamRotZ      += ROT_ANGLE_STEP;
            RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
            refreshNeeded   = 1;
    } else if (c == keyTurnRight) {
            rayCamRotZ      -= ROT_ANGLE_STEP; 
            RayLeftAlpha    = rayCamRotZ + HALF_FOV_FIX_ANGLE;
            refreshNeeded   = 1;
    } else if (c == keyStraffeRight) {
            refreshNeeded           = 1;
            shiftRight();
    } else if (c == keyStraffeLeft) {
            refreshNeeded           = 1;
            shiftLeft();
    } else if (c == keyQuit) {
            running = 0;
    }

}

void keyReleased(unsigned char c){
	// printf ("kr: %x, ", c);
}

void lsys(){
	unsigned char c;
	while (nbE_keybuf != 0) {
		if ((c=get_keyevent()) & 0x80){
			keyReleased (c & 0x7F);
		} else {
			keyPressed (c);
		}
	}
}



void maze(){

    hires();
   
    prepareRGB();

	kernelInit();
	osmeInit();
	ayInit();

    mmiInit ();
    refreshNeeded           = 1;
    running                 = 1;

	do {
		lsys();
        if (isWinningPosition(rayCamPosX, rayCamPosY)) {
            running = 0;
            maze_completed  = 1;
        }
        if (refreshNeeded) {
            rayInitCasting();
            rayProcessPoints();
            rayProcessWalls();
            drawWalls();
            refreshNeeded = 0;
        }
        if (remaining_seconds == nxtPing){
            if (soundenabled) ping();
            nxtPing = tabTempoPing[++idxTempoPing];
        }
    } while (running && (remaining_seconds != 0));
    if ((remaining_seconds == 0) && (soundenabled)) explode();
	kernelEnd();
}




char mainChoice(){
    char c=0;
    do {
        welcome();
        c = get();
        while ((c == 'C') || (c == 'O') || (c == '0')){
            if (c == 'C') {
                credits();
            } else if ((c == 'O')|| (c == '0')) {
                options();
            }
            c=0;
        }
    } while ((c != '1') && (c != '2') && (c != '3') && (c != KEY_ESCAPE)) ;
    return c;
}




void playLab(signed char init_0x[], signed char scene_0x[], unsigned char *texture_0x[]
    , unsigned char (*collision_0x)(signed char , signed char )
    , unsigned char (*win_0x)(signed char , signed char )){

        wanna_retry             = 1;
        maze_completed          = 0;

        while (wanna_retry && !maze_completed) {

            initCamera(init_0x);
            initScene (scene_0x, texture_0x, collision_0x, win_0x);
            
            nxtPing                 = tabTempoPing[idxTempoPing];
            maze();

            if (!maze_completed) {
                if (remaining_seconds!=0) get(); // flush escape char 
                if (wanna_retry = (retry()=='R')) {
                    remaining_seconds       = tabLevelParam[currentIdxParam-2]; // game_level * 35 ; // 35 = Difficile
                    idxTempoPing            = tabLevelParam[currentIdxParam-1];
                }
            }
        }
}

// void intro()
// {
//     int i;
// 	paper(6);ink(4);

// 	// scrolling hybrid graphics mode : Text & Hires
// 	poke(0xbb80+40,30); 
// 	for (i=8;i<16;i++)
// 		poke(0xA000+(40*i)+2,26);

// 	// Scrolling Text colors
// 	*(unsigned char*)(0xA000+(40*8)+1)=1&7;
// 	*(unsigned char*)(0xA000+(40*9)+1)=5&7;
// 	*(unsigned char*)(0xA000+(40*10)+1)=3&7;
// 	*(unsigned char*)(0xA000+(40*11)+1)=7&7;
// 	*(unsigned char*)(0xA000+(40*12)+1)=3&7;
// 	*(unsigned char*)(0xA000+(40*13)+1)=5&7;
// 	*(unsigned char*)(0xA000+(40*14)+1)=1&7;
// 	*(unsigned char*)(0xA000+(40*15)+1)=0&7;
	
//     AdvancedPrint(0,0,"                                        ");
// 	AdvancedPrint(2,1,"                                      ");
// 	// clear background
// 	for (i=16;i<28;i++)
// 	{
// 		AdvancedPrint(2,i,"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm");
// 		poke(0xBB80+1+(i*40),4);
// 	}
	
// 	// screen of menu page
// 	AdvancedPrint(2,2,"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm");
// 	AdvancedPrint(2,3,"mmmmmmm     mmmm    mmm mm mmmm mmmmmm");
// 	AdvancedPrint(2,4,"mmmmmm! !!!! mm !!!! m!mm!  mm! mmmmmm");
// 	AdvancedPrint(2,5,"mmmmmm! mmm! m! mmm! mm m! ! m! mmmmmm");
// 	AdvancedPrint(2,6,"mmmmmm!     mm!      m! m! m! ! mmmmmm");
// 	AdvancedPrint(2,7,"mmmmmm! !!! mm! !!!! m! m! mm!  mmmmmm");
// 	AdvancedPrint(2,8,"mmmmmm! mm!! m! mmm! m! m! mmm! mmmmmm");
// 	AdvancedPrint(2,9,"mmmmmm!mmmm!mm!mmmm!mm!mm!mmmm!mmmmmmm");
// 	AdvancedPrint(2,10,"mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm");
// 	AdvancedPrint(2,11, "mmm     mmmm    mmm mmmm mm mmm    mmm");
// 	AdvancedPrint(2,12,"mm! !!!! mm !!!! m!  mm! m!mmm !!!! mm");
// 	AdvancedPrint(2,13,"mm! mmm! m! mmm! m! ! m! mm m! mmm!mmm");
// 	AdvancedPrint(2,14,"mm!     mm!      m! m! ! m! m! mmmmmmm");
// 	AdvancedPrint(2,15,"mm! !!!mmm! !!!! m! mm!  m! m! mmmm mm");
// 	AdvancedPrint(2,16,"mm! mmmmmm! mmm! m! mmm! m! mm!    mmm");
// 	AdvancedPrint(2,17,"mm!mmmmmmm!mmmm!mm!mmmm!mm!mmmm!!!mmmm");
// 	AdvancedPrint(6,21,"\23\4DIRECTION : ARROWS KEY < > \4\26");
// 	AdvancedPrint(13,23,"\23\4SPACE TO JUMP\4\26");
// 	AdvancedPrint(10,25,"\23\4PRESS SPACE TO PLAY\4\26");
//     // text color   // 12 = blink

// 	// color_inverse_menu();
	
// 	poke(0xBB80+(25*40)+9,12);
// 	poke(0xBB80+(25*40)+31,8);
	 
	 
// 	// to debbug
// 	// gotoxy(20,0);printf("CODE=%d IDX=%d",rain[index_raindrop],index_raindrop);
// }
// unsigned char charset[] = {
//         85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85
//         , 0, 0, 0, 0, 0, 0, 0, 0, 8, 8, 8, 8, 8, 0, 8, 0
//         , 20, 20, 20, 0, 0, 0, 0, 0, 20, 20, 62, 20, 62, 20, 20, 0
//         , 8, 30, 40, 28, 10, 60, 8, 0, 48, 50, 4, 8, 16, 38, 6, 0
//         , 16, 40, 40, 16, 42, 36, 26, 0, 12, 12, 24, 0, 0, 0, 0, 0
//         , 8, 24, 48, 48, 48, 24, 8, 0, 8, 12, 6, 6, 6, 12, 8, 0
//         , 8, 42, 28, 8, 28, 42, 8, 0, 8, 8, 8, 62, 8, 8, 8, 0
//         , 0, 0, 0, 0, 0, 24, 24, 48, 0, 0, 0, 0, 62, 0, 0, 0
//         , 0, 0, 0, 0, 0, 24, 24, 0, 0, 2, 4, 8, 16, 32, 0, 0
//         , 28, 62, 54, 54, 54, 62, 28, 0, 12, 28, 28, 12, 12, 62, 62, 0
//         , 60, 62, 6, 28, 48, 62, 30, 0, 28, 62, 6, 12, 6, 62, 28, 0
//         , 54, 54, 62, 62, 6, 6, 6, 0, 62, 62, 48, 60, 6, 62, 28, 0
//         , 12, 24, 48, 60, 54, 62, 28, 0, 62, 62, 6, 12, 24, 24, 24, 0
//         , 28, 62, 54, 28, 54, 62, 28, 0, 28, 54, 54, 30, 6, 28, 24, 0
//         , 0, 0, 8, 0, 0, 8, 0, 0, 0, 0, 8, 0, 0, 8, 8, 16
//         , 4, 8, 16, 32, 16, 8, 4, 0, 0, 0, 62, 0, 62, 0, 0, 0
//         , 16, 8, 4, 2, 4, 8, 16, 0, 28, 34, 4, 8, 8, 0, 8, 0
//         , 30, 34, 42, 46, 44, 32, 30, 0, 28, 62, 54, 62, 62, 54, 54, 0
//         , 60, 54, 54, 60, 54, 54, 60, 0, 28, 62, 54, 48, 54, 62, 28, 0
//         , 60, 62, 54, 54, 54, 62, 60, 0, 62, 62, 48, 60, 48, 62, 62, 0
//         , 62, 62, 48, 60, 60, 48, 48, 0, 30, 62, 48, 54, 54, 62, 26, 0
//         , 54, 54, 54, 62, 54, 54, 54, 0, 62, 62, 8, 8, 8, 62, 62, 0
//         , 6, 6, 6, 6, 54, 62, 28, 0, 50, 54, 60, 56, 60, 54, 50, 0
//         , 56, 56, 56, 56, 56, 62, 62, 0, 34, 54, 62, 62, 62, 54, 54, 0
//         , 38, 54, 62, 62, 62, 54, 50, 0, 28, 62, 54, 54, 54, 62, 28, 0
//         , 60, 54, 54, 60, 48, 48, 48, 0, 28, 54, 54, 54, 62, 60, 26, 0
//         , 60, 54, 54, 60, 56, 60, 54, 0, 28, 54, 48, 28, 6, 54, 28, 0
//         , 62, 62, 8, 8, 8, 8, 8, 0, 54, 54, 54, 54, 54, 62, 28, 0
//         , 54, 54, 54, 62, 28, 28, 8, 0, 54, 54, 54, 62, 62, 54, 34, 0
//         , 54, 54, 28, 8, 28, 54, 54, 0, 54, 54, 54, 28, 8, 8, 8, 0
//         , 62, 62, 4, 8, 16, 62, 62, 0, 30, 30, 24, 24, 24, 30, 30, 0
//         , 0, 32, 16, 8, 4, 2, 0, 0, 60, 60, 12, 12, 12, 60, 60, 0
//         , 28, 28, 28, 28, 28, 28, 0, 0, 14, 16, 16, 60, 16, 16, 62, 0
//         , 12, 18, 45, 41, 45, 18, 12, 0, 0, 0, 28, 6, 30, 54, 30, 0
//         , 48, 48, 60, 62, 54, 62, 60, 0, 0, 0, 30, 62, 48, 62, 30, 0
//         , 6, 6, 30, 62, 54, 62, 30, 0, 0, 0, 28, 54, 62, 48, 30, 0
//         , 12, 30, 24, 60, 24, 24, 24, 0, 0, 0, 28, 54, 54, 30, 6, 60
//         , 48, 48, 60, 62, 54, 54, 54, 0, 24, 0, 56, 24, 24, 24, 60, 0
//         , 12, 0, 28, 12, 44, 60, 24, 0, 48, 48, 50, 52, 56, 52, 50, 0
//         , 56, 24, 24, 24, 24, 24, 60, 0, 0, 0, 34, 54, 62, 54, 54, 0
//         , 0, 0, 60, 62, 54, 54, 54, 0, 0, 0, 28, 54, 54, 54, 28, 0
//         , 0, 0, 60, 54, 54, 60, 48, 48, 0, 0, 30, 54, 54, 30, 6, 6
//         , 0, 0, 54, 56, 48, 48, 48, 0, 0, 0, 30, 48, 28, 6, 60, 0
//         , 24, 24, 62, 24, 26, 30, 12, 0, 0, 0, 54, 54, 54, 62, 26, 0
//         , 0, 0, 54, 54, 54, 28, 8, 0, 0, 0, 54, 54, 62, 54, 34, 0
//         , 0, 0, 34, 54, 28, 54, 34, 0, 0, 0, 54, 54, 54, 30, 6, 28
//         , 0, 0, 62, 4, 8, 16, 62, 0, 0, 0, 1, 1, 3, 2, 36, 24
//         , 28, 34, 0, 0, 57, 1, 2, 4, 0, 0, 0, 32, 25, 2, 4, 7
//         , 0, 0, 0, 0, 48, 9, 18, 36, 0, 0, 0, 0, 54, 9, 17, 2
//         };

#include "myHires.c"
extern unsigned char charset[];


void main(){

    char c=0;

    // Deactivate cursor and keyclick
    mode0 = peek(0x26A);
    
    poke(0x26A, (mode0 | 0x08) & 0xFE);

    // intro();
    // get();
    //memcpy ((void*)(0xB400),(void*)(charset),1024);
    // printf ("Coucou :-)"); get();

    myHires();
    poke(0xBF68, 16); poke(0xBF69, 7);
    poke(0xBF90, 16); poke(0xBF91, 7);
    poke(0xBFB8, 16); poke(0xBFB9, 7);
    poke(0x26A, (mode0 | 0x08) & 0xFE);
    waitkey();
    text();
    
    paper(0); ink(7);
    do {
        c = mainChoice();
        if (c == KEY_ESCAPE) break ;

        game_level              = (unsigned char)(c-'1');
        current_score           = 0;
        currentIdxParam         = game_level<<1;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        playLab(init_04, scene_04, texture_04, 0, win_04);
        
        // playLab(init_07, scene_07, texture_07, 0, win_07);
        // playLab(init_11, scene_11, texture_11, 0, win_11);
        // playLab(init_09, scene_09, texture_09, 0, win_09);
        // playLab(init_00, scene_00, texture_00, 0, win_00);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;



        currentIdxParam+=4;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        playLab(init_05, scene_05, texture_05, 0, win_05);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;



        currentIdxParam+=4;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        playLab(init_02, scene_02, texture_02, 0, win_02);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;


        currentIdxParam+=4;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        playLab(init_07, scene_07, texture_07, 0, win_07);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;


        currentIdxParam+=4;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        playLab(init_09, scene_09, texture_09, 0, win_09);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;



        currentIdxParam+=4;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        wanna_retry             = 1;
        maze_completed          = 0;

        playLab(init_01, scene_01, texture_01, 0, win_01);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;





        currentIdxParam+=4;

        remaining_seconds       = tabLevelParam[currentIdxParam++]; // game_level * 35 ; // 35 = Difficile
        idxTempoPing            = tabLevelParam[currentIdxParam++];

        wanna_retry             = 1;
        maze_completed          = 0;

        playLab(init_11, scene_11, texture_11, 0, win_11);

        if (! maze_completed) continue;

        c = congrats();
        if (c == KEY_ESCAPE) continue ;





    } while (1);

    bye();

    // Reactivate cursor and keyclick
    poke(0x26A, mode0);

}
// #define LORES_SCREEN_ADDRESS            ((unsigned int)0xBB80)
// #define STANDARD_CHARSET_ADDRESS        ((unsigned int)0xB400)
// #define ALTERNATE_CHARSET_ADDRESS       ((unsigned int)0xB800)
// #define STANDARD_HIRES_CHARSET_ADDRESS  ((unsigned int)0x9800)

// #define CHANGE_INK_TO_BLACK	            0		
// #define CHANGE_INK_TO_YELLOW	        3		
// #define CHANGE_INK_TO_MAGENTA           5			
// #define CHANGE_INK_TO_CYAN	            6		
// #define CHANGE_INK_TO_WHITE	            7	


// #define USE_STANDARD_CHARSET    	                    8		
// #define USE_ALTERNATE_CHARSET	                        9		
// #define USE_DOUBLE_SIZE_STANDARD_CHARSET	            10		
// #define USE_DOUBLE_SIZE_ALTERNATE_CHARSET	            11		
// #define USE_DOUBLE_SIZE_BLINKING_STANDARD_CHARSET       12		
// #define USE_DOUBLE_SIZE_BLINKING_ALTERNATE_CHARSET      13		
// #define USE_BLINKING_STANDARD_CHARSET	                14		
// #define USE_BLINKING_ALTERNATE_CHARSET	                15		
// // Change Paper (background) color	
// #define CHANGE_PAPER_TO_BLACK			                16		
// #define CHANGE_PAPER_TO_RED	                            17		
// #define CHANGE_PAPER_TO_GREEN	                        18		
// #define CHANGE_PAPER_TO_YELLOW	                        19		
// #define CHANGE_PAPER_TO_BLUE	                        20		
// #define CHANGE_PAPER_TO_MAGENTA	                        21		
// #define CHANGE_PAPER_TO_CYAN	                        22		
// #define CHANGE_PAPER_TO_WHITE	                        23		
// // Video control attributes	
// #define SWITCH_TO_TEXT_MODE_60HZ		                24		
// #define SWITCH_TO_TEXT_MODE_50HZ		                26		
// #define SWITCH_TO_HIRES_MODE_60HZ	                    28		
// #define SWITCH_TO_HIRES_MODE_50HZ                       30		

// /*
//  * VISIBILITY LIMITS
//  */
// #define ANGLE_MAX 0xC0
// #define ANGLE_VIEW 0xE0


// unsigned int multi40[] = {
//         0, 40, 80, 120, 160, 200, 240, 280, 320, 360, 400, 440, 480, 520, 560, 600
//         , 640, 680, 720, 760, 800, 840, 880, 920, 960, 1000, 1040, 1080, 1120, 1160, 1200, 1240
//         // , 1280, 1320, 1360, 1400, 1440, 1480, 1520, 1560, 1600, 1640, 1680, 1720, 1760, 1800, 1840, 1880
//         // , 1920, 1960, 2000, 2040, 2080, 2120, 2160, 2200, 2240, 2280, 2320, 2360, 2400, 2440, 2480, 2520
//         // , 2560, 2600, 2640, 2680, 2720, 2760, 2800, 2840, 2880, 2920, 2960, 3000, 3040, 3080, 3120, 3160
//         // , 3200, 3240, 3280, 3320, 3360, 3400, 3440, 3480, 3520, 3560, 3600, 3640, 3680, 3720, 3760, 3800
//         // , 3840, 3880, 3920, 3960, 4000, 4040, 4080, 4120, 4160, 4200, 4240, 4280, 4320, 4360, 4400, 4440
//         // , 4480, 4520, 4560, 4600, 4640, 4680, 4720, 4760, 4800, 4840, 4880, 4920, 4960, 5000, 5040, 5080
//         // , 5120, 5160, 5200, 5240, 5280, 5320, 5360, 5400, 5440, 5480, 5520, 5560, 5600, 5640, 5680, 5720
//         // , 5760, 5800, 5840, 5880, 5920, 5960, 6000, 6040, 6080, 6120, 6160, 6200, 6240, 6280, 6320, 6360
//         // , 6400, 6440, 6480, 6520, 6560, 6600, 6640, 6680, 6720, 6760, 6800, 6840, 6880, 6920, 6960, 7000
//         // , 7040, 7080, 7120, 7160, 7200, 7240, 7280, 7320, 7360, 7400, 7440, 7480, 7520, 7560, 7600, 7640
//         // , 7680, 7720, 7760, 7800, 7840, 7880, 7920, 7960
//         };

// unsigned int multi27[] = {
//         0, 27, 54, 81, 108, 135, 162, 189, 216, 243, 270, 297, 324, 351, 378, 405
//         , 432, 459, 486, 513, 540, 567, 594, 621, 648, 675, 702, 729, 756, 783, 810, 837
//         , 864, 891, 918, 945, 972, 999, 1026, 1053};


// unsigned char idxWall[] = {
//         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//         , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//         , 0, 0, 0, 0, 0, 0, 0, 0};

// line in [0..65] column in [0..79]
// void colorSquare(unsigned char line, unsigned char column, unsigned char theColor){

//     unsigned char r, g, b;
//     unsigned char *adr;

//     PROFILE_ENTER(ROUTINE_COLORSQUARE);
//     // retrieve the color components from the color value
//     r = (theColor>>4)& 0x03;
//     g = (theColor>>2)& 0x03;
//     b = (theColor)& 0x03;

//     // compute the start adress of the screen square to color
//     //adr = (unsigned char *)(HIRES_SCREEN_ADDRESS + (line*3)*NEXT_SCANLINE_INCREMENT + (column>>1));
//     adr = (unsigned char *)(HIRES_SCREEN_ADDRESS + multi40[(line<<1) + line] + (column>>1));

//     if ((column&0x01) == 0){
//         *adr |= encodeHColor[r];
//         adr += NEXT_SCANLINE_INCREMENT;
//         *adr |= encodeHColor[g];
//         adr += NEXT_SCANLINE_INCREMENT;
//         *adr |= encodeHColor[b];
//     } else {
//         *adr |= encodeLColor[r];
//         adr += NEXT_SCANLINE_INCREMENT;
//         *adr |= encodeLColor[g];
//         adr += NEXT_SCANLINE_INCREMENT;
//         *adr |= encodeLColor[b];
//     }

//     PROFILE_LEAVE(ROUTINE_COLORSQUARE);
// }

// void drawImage01(){
//     int ii, jj;

//     signed char idxScreenLine, idxScreenCol;
//     unsigned char height, texcolumn;

//     PROFILE_ENTER(ROUTINE_DRAW01);
//     for (ii = 0; ii < 40; ii++) {
//         height          = tabHeight[ii];
//         texcolumn       = tabTexCol[ii];
//         idxScreenCol    = 10+ii;

//         ddaStartValue       = 0;
//         ddaNbStep           = 2*height;
//         ddaNbVal            = TEXTURE_SIZE;

//         ddaInit();
//         idxScreenLine       = 32 - height;
//         // printf ("%d %d\n", ddaCurrentValue, idxScreenLine);
//         if ((idxScreenLine >=0) && (idxScreenLine < 64)) {
//             colorSquare(idxScreenLine, idxScreenCol, bufimg[multi40[ddaCurrentValue] + texcolumn]);
//         }
//         while (ddaCurrentValue < ddaEndValue) {
//             (*ddaStepFunction)(); 
//             // printf ("%d\n", ddaCurrentValue, idxScreenLine);
//             if ((idxScreenLine >=0) && (idxScreenLine < 64)) {
//                 colorSquare(idxScreenLine, idxScreenCol, bufimg[multi40[ddaCurrentValue] + texcolumn]);
//             }
//             idxScreenLine   += 1;
//         }
//     }
//     PROFILE_LEAVE(ROUTINE_DRAW01);
// }


