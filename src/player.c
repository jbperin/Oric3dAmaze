
#include "collision.c"

#define ROT_ANGLE_STEP 16
/*    ___  _                           
 *   / _ \| |  __ _  _   _   ___  _ __ 
 *  / /_)/| | / _` || | | | / _ \| '__|
 * / ___/ | || (_| || |_| ||  __/| |   
 * \/     |_| \__,_| \__, | \___||_|   
 *                   |___/             
 */
void forward();
void shiftLeft();
void backward();
void shiftRight();

// [ref camera_situation]

void player () {
    switch (key()) {
    case 8:  // left 
        rayCamRotZ += ROT_ANGLE_STEP;
        RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;
        break;
    case 9:  // right 
        rayCamRotZ -= ROT_ANGLE_STEP; 
        RayLeftAlpha            = rayCamRotZ + HALF_FOV_FIX_ANGLE;
        break;
    case 10:  // down
        backward(); break;
    case 11:  // up
        forward(); break;
    // case 80:  // P        HEP !! DONT TOUCH THAT !!!
    //     glCamPosZ += 1; break;
    // case 59:  // ;       FORGET ABOUT IT !!
    //     glCamPosZ -= 1; break;
    case 81:  // Q
        running = 0; break;
    // case 65:  // A
    //     glCamRotX -= 2; break;
    case 90:  // Z
        shiftLeft(); break;
    case 88:  // X
        shiftRight(); break;
    default:
        break;
    }
}
/*                          
 *   /\/\    ___  __   __  ___ 
 *  /    \  / _ \ \ \ / / / _ \
 * / /\/\ \| (_) | \ V / |  __/
 * \/    \/ \___/   \_/   \___|
 *                            
 */

void forward() {
    signed int X, Y;
    X = rayCamPosX; Y = rayCamPosY;
    if (-112 >= rayCamRotZ) {
        // rayCamPosX--;
        asm("dec _rayCamPosX;");
    } else if ((-112 < rayCamRotZ) && (-80 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY--;
        asm("dec _rayCamPosX;dec _rayCamPosY;");
    } else if ((-80 < rayCamRotZ) && (-48 >= rayCamRotZ)) {
        // rayCamPosY--;
        asm("dec _rayCamPosY;");
    } else if ((-48 < rayCamRotZ) && (-16 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY--;
        asm("inc _rayCamPosX;dec _rayCamPosY;");
    } else if ((-16 < rayCamRotZ) && (16 >= rayCamRotZ)) {
        // rayCamPosX++;
        asm("inc _rayCamPosX;");
    } else if ((16 < rayCamRotZ) && (48 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY++;
        asm("inc _rayCamPosX;inc _rayCamPosY;");
    } else if ((48 < rayCamRotZ) && (80 >= rayCamRotZ)) {
        // rayCamPosY++;
        asm("inc _rayCamPosY;");
    } else if ((80 < rayCamRotZ) && (112 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY++;
        asm("dec _rayCamPosX;inc _rayCamPosY;");
    } else {
        // rayCamPosX--;
        asm("dec _rayCamPosX;");
    }
#ifdef USE_GENERIC_COLLISION
    if (isInWall(rayCamPosX, rayCamPosY)){
#else
    if (!isAllowedPosition(rayCamPosX, rayCamPosY)) {
#endif
        rayCamPosX = X; rayCamPosY = Y;
    }
}
void backward() {
    signed int X, Y;
    X = rayCamPosX; Y = rayCamPosY;
    if (-112 >= rayCamRotZ) {
        // rayCamPosX++;
        asm("inc _rayCamPosX;")
    } else if ((-112 < rayCamRotZ) && (-80 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY++;
        asm("inc _rayCamPosX;inc _rayCamPosY;")
    } else if ((-80 < rayCamRotZ) && (-48 >= rayCamRotZ)) {
        // rayCamPosY++;
        asm("inc _rayCamPosY;");
    } else if ((-48 < rayCamRotZ) && (-16 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY++;
        asm("dec _rayCamPosX;inc _rayCamPosY;");
    } else if ((-16 < rayCamRotZ) && (16 >= rayCamRotZ)) {
        // rayCamPosX--;
        asm("dec _rayCamPosX;");
    } else if ((16 < rayCamRotZ) && (48 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY--;
        asm("dec _rayCamPosX;dec _rayCamPosY;");
    } else if ((48 < rayCamRotZ) && (80 >= rayCamRotZ)) {
        // rayCamPosY--;
        asm("dec _rayCamPosY;");
    } else if ((80 < rayCamRotZ) && (112 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY--;
        asm("inc _rayCamPosX;dec _rayCamPosY;");
    } else {
        // rayCamPosX++;
        asm("inc _rayCamPosX;");
    }
#ifdef USE_GENERIC_COLLISION
    if (isInWall(rayCamPosX, rayCamPosY)){
#else
    if (!isAllowedPosition(rayCamPosX, rayCamPosY)) {
#endif
        rayCamPosX = X; rayCamPosY = Y;
    }
}
void shiftLeft() {
    signed int X, Y;
    X = rayCamPosX; Y = rayCamPosY;
    if (-112 >= rayCamRotZ) {
        // rayCamPosY--;
        asm("dec _rayCamPosY;");
    } else if ((-112 < rayCamRotZ) && (-80 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY--;
        asm("inc _rayCamPosX;dec _rayCamPosY;");
    } else if ((-80 < rayCamRotZ) && (-48 >= rayCamRotZ)) {
        // rayCamPosX++;
        asm("inc _rayCamPosX;");
    } else if ((-48 < rayCamRotZ) && (-16 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY++;
        asm("inc _rayCamPosX;inc _rayCamPosY;");
    } else if ((-16 < rayCamRotZ) && (16 >= rayCamRotZ)) {
        // rayCamPosY++;
        asm("inc _rayCamPosY;");
    } else if ((16 < rayCamRotZ) && (48 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY++;
        asm("dec _rayCamPosX;inc _rayCamPosY;");
    } else if ((48 < rayCamRotZ) && (80 >= rayCamRotZ)) {
        // rayCamPosX--;
        asm("dec _rayCamPosX;");
    } else if ((80 < rayCamRotZ) && (112 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY--;
        asm("dec _rayCamPosX;dec _rayCamPosY;");
    } else {
        // rayCamPosY--;
        asm("dec _rayCamPosY;");
    }
#ifdef USE_GENERIC_COLLISION
    if (isInWall(rayCamPosX, rayCamPosY)){
#else
    if (!isAllowedPosition(rayCamPosX, rayCamPosY)) {
#endif
        rayCamPosX = X; rayCamPosY = Y;
    }
}
void shiftRight() {
    signed int X, Y;
    X = rayCamPosX;
    Y = rayCamPosY;
    if (-112 >= rayCamRotZ) {
        // rayCamPosY++;
        asm("inc _rayCamPosY;");
    } else if ((-112 < rayCamRotZ) && (-80 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY++;
        asm("dec _rayCamPosX;inc _rayCamPosY;");
    } else if ((-80 < rayCamRotZ) && (-48 >= rayCamRotZ)) {
        // rayCamPosX--;
        asm("dec _rayCamPosX;");
    } else if ((-48 < rayCamRotZ) && (-16 >= rayCamRotZ)) {
        // rayCamPosX--; rayCamPosY--;
        asm("dec _rayCamPosX;dec _rayCamPosY;");
    } else if ((-16 < rayCamRotZ) && (16 >= rayCamRotZ)) {
        // rayCamPosY--;
        asm("dec _rayCamPosY;");
    } else if ((16 < rayCamRotZ) && (48 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY--;
        asm("inc _rayCamPosX;dec _rayCamPosY;");
    } else if ((48 < rayCamRotZ) && (80 >= rayCamRotZ)) {
        // rayCamPosX++;
        asm("inc _rayCamPosX;");
    } else if ((80 < rayCamRotZ) && (112 >= rayCamRotZ)) {
        // rayCamPosX++; rayCamPosY++;
        asm("inc _rayCamPosX;inc _rayCamPosY;");
    } else {
        // rayCamPosX++;
        asm("inc _rayCamPosX;");
    }
#ifdef USE_GENERIC_COLLISION
    if (isInWall(rayCamPosX, rayCamPosY)){
#else
    if (!isAllowedPosition(rayCamPosX, rayCamPosY)) {
#endif
        rayCamPosX = X; rayCamPosY = Y;
    }
}
