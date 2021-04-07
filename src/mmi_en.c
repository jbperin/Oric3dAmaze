

#include "keyboard_c.c"

#define CLS text();cls();poke (0xBBA3, CHANGE_INK_TO_BLACK);poke(0x26A, (mode0 | 0x08) & 0xFE);

void waitkey () {
    sprintf (0xBF70, "Press a key ...");
    get();
}

void mmiInit(){
    sprintf (message, "Remaining time");
    AdvancedPrint(1,26, message);
}
void credits(){

    CLS
    sprintf (0xBB80, "\012\001  --== Oric 3D aMaze ==--    ");
    printf ("\033J\033A--== Oric 3D aMaze ==--    "
    "\n\n"
    "  Created and developed by: \n\n"
    "       Jean-Baptiste PERIN (JiBe)\n\n"
    "  Advised by: \n\n"
    "        Mickael POINTIER (Dbug)\n\n"
    "        Vincent BILLET (Xaratheus)\n\n\n\n\n");
//     printf("\n\ncon contribuciones de\n"
// "Tu nombre\n"
// "y el benevolente estímulo de\n"
// "\n"
//     );
    printf("\n\n\n\nThis game uses castoric for 3D\n\n"
    "\033Dgithub.com/oric-software/castoric\033G\n"
    " ---------------------------------\n"
    );
    get();
}
void setKeyboard(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== KEYBOARD SETTING ==--    ");
    printf ("\033J\033A   --== KEYBOARD SETTING ==--    "
        "\n\n"
        "Select your preferred keyboard \n"
        "    configuration by pressing  \n"
        "    key 1, 2 or 3:\n");

        printf ("\n\033D[1]\033G: \n\n"
        "  LEFT/RIGHT : Turn Left / Right\n"
        "  UP/DOWN    : Forward / Backward\n"
        "  X / C      : Straffe Left / Right\n");

        printf ("\n\033D[2]\033G: \n\n"

        "  Q / E : Turn Left / Right\n"
        "  W / S : Forward / Backward\n"
        "  Z / D : Straffe Left / Right\n");

        printf ("\n\033D[3]\033G: \n\n"
        "  T / U : Turn Left / Right\n"
        "  Y / H : Forward / Backward\n"
        "  G / J : Straffe Left / Right\n"        );
    } while (((c=get()) != '1') && (c != '2') && (c != '3'));
    keybconfig = c-'1';
    setKeyboardConfig();
}

void setSound(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== SOUND SETTING ==--    ");
    printf ("\033J\033A   --== SOUND SETTING ==--    "
        "\n\n"
        " \033D[1]\033G: Sound disabled\n\n"
        " \033D[2]\033G: Sound enabled\n\n"
        );
    } while (((c=get()) != '1') && (c != '2'));
    soundenabled = c-'1';
}

void options(){
    setKeyboard();
    setSound ();
}

void welcome(){
    CLS
    sprintf (0xBB80, "\012\001       --== Oric 3D aMaze ==--        ");
    printf ("\033J\033A     --== Oric 3D aMaze ==--        "
"     by Jean-Baptiste PERIN (2021)\n\n"
"Your teleportation to the heart of \n"
"enemy cities allows us to trigger\n"
"their programmed explosion.\n");
    printf ("But this situation exposes you because"
"the explosion is imminent and you must"
"not stay.\n"
"Leave as fast as you can ...\n\n");
    printf ("Press :\n\n"
"-\033D1\033G Easy\n"
"-\033D2\033G Medium\n"
"-\033D3\033G Hard\n"
"-\033DC\033G Credits\n"
"-\033DO\033G Options\n\n");
setKeyboardConfig();
if (keybconfig==0) {
    printf ("Controls:\n\n"
"\033DUP / DOWN \033G: Forward / Backward\n"
"\033DLEFT/RIGHT\033G: Turn Left / Right\n"
"\033DX / C     \033G: Straffe Left / Right\n"
"\033DESC       \033G: Exit");
} else if (keybconfig==1){
    printf ("Controls:\n\n"
"\033DW / S\033G: Forward / Backward\n"
"\033DQ / E\033G: Turn Left / Right\n"
"\033DZ / D\033G: Straffe Left / Right\n"
"\033DESC  \033G: Exit");
} else if (keybconfig==2){
    printf ("Controls:\n\n"
"\033DY / H\033G: Forward / Backward\n"
"\033DT / U\033G: Turn Left / Right\n"
"\033DG / J\033G: Straffe Left / Right\n"
"\033DESC  \033G: Exit");

    // poke(0xbbd1,10);
    // poke(0xbbf9,10);
}

}
void wanaContinue(){
    printf("Press:\n\n");
    printf ("-\033DC\033G to continue,\n\n");
    printf ("-\033DESC\033G to exit.");
}
void bye() {
    text();cls();paper(7); ink(0);
    sprintf (0xBB80, "                                       ");
    printf (" Thanks for playing \n\n"
    "    --== Oric 3D aMaze ==--\n\n"
    "    by Jean-Baptiste PERIN (2021)\n\n");
}
char  retry() {
    char c;
    
    do {
        CLS
        sprintf (0xBB80, "\012\001        --== BAD DREAM ==--        ");
        printf ("\033J\033A      --== BAD DREAM ==--        ");
        printf("\n\n\n\n");
        printf("Damn !!\n\nWhat a horrible nightmare you just made !\n\n");
        printf("You had dozed off and dreamed that\nyou were stuck in the explosion\n\n");
        printf("Fortunately, all this was just a\nbad dream\n\n");
        printf("Take time to come to your senses\nand then press\n\n");
        printf ("-\033DR\033G to resume adventure,\n\n");
        printf ("-\033DESC\033G to exit.");
        c=get();
    } while ((c != 'R') && (c!= KEY_ESCAPE)); //&& (c!= KEY_ESCAPE)
    return c;
}

char  congrats() {

    char c;

    computeNewScore();

    CLS
    sprintf (0xBB80, "\012\001        --== CONGRATULATIONS ==--      ");
    printf ("\033J\033A      --== CONGRATULATIONS ==--      ");
    printf("\n\n\n\n");
    printf("You escaped in %d seconds.\n\n",tabLevelParam[currentIdxParam-2]- remaining_seconds);
    printf("There were only %d seconds left before\nthe explosion.\n\n",remaining_seconds);

    if (game_level == 0)
        printf("Your EASY level score");
    else if (game_level == 1)
        printf("Your MEDIUM level score");
    else if (game_level == 2)
        printf("Your HARD level score");
    printf(" is now :\n\n   %d points\n\n\n\n\n", current_score);

    wanaContinue();
    while (((c=get()) != 'C') && (c!= KEY_ESCAPE));
    return c;
}