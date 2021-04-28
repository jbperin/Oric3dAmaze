

#include "keyboard_c.c"

#define CLS text();cls();poke (0xBBA3, CHANGE_INK_TO_BLACK);poke(0x26A, (mode0 | 0x08) & 0xFE);

void waitkey () {
    sprintf (0xBF70, "Appuyez sur une touche ...");
    get();
}

void mmiInit(){
    sprintf (message, "Temps restant:");
    AdvancedPrint(3,26, message);
}
void credits(){

    CLS
    sprintf (0xBB80, "\012\001  --== Les Chemins de Galdeon ==--    ");
    printf ("\033J\033A--== Les Chemins de Galdeon ==--    "
    "\n\n"
    "    Cree et developpe par: \n\n"
    "       Jean-Baptiste PERIN (JiBe)\n\n"
    "    conseille par: \n\n"
    "        Mickael POINTIER (Dbug)\n\n"
    "        Vincent BILLET (Xaratheus)\n\n\n\n\n");
    printf("\n\n\n\nCe jeu utilise castoric pour la 3D\n\n"
    "\033Dgithub.com/oric-software/castoric\033G\n"
    " ---------------------------------\n"
    );
    get();
}
void setKeyboard(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== PARAMETRAGE CLAVIER ==--    ");
    printf ("\033J\033A   --== PARAMETRAGE CLAVIER ==--    "
        "\n\n"
        "Selectionner votre configuration \n"
        "    clavier preferee en appuyant sur \n"
        "    la touche 1, 2 ou 3:\n");

        printf ("\n\033D[1]\033G: \n\n"
        "  LEFT/RIGHT : tourner gauche/droite\n"
        "  UP/DOWN    : avancer / reculer\n"
        "  X / C     : decaler gauche / droite\n");

        printf ("\n\033D[2]\033G: \n\n"

        "  Q / E : tourner gauche / droite\n"
        "  W / S : avancer / reculer\n"
        "  Z / D : decaler gauche / droite\n");

        printf ("\n\033D[3]\033G: \n\n"
        "  T / U : tourner gauche / droite\n"
        "  Y / H : avancer / reculer\n"
        "  G / J : decaler gauche / droite\n"        );
    } while (((c=get()) != '1') && (c != '2') && (c != '3'));
    keybconfig = c-'1';
    setKeyboardConfig();
}

void setSound(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== PARAMETRAGE SONS ==--    ");
    printf ("\033J\033A   --== PARAMETRAGE SONS ==--    "
        "\n\n"
        " \033D[1]\033G: Sons desactives\n\n"
        " \033D[2]\033G: Sons actives\n\n"
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
    sprintf (0xBB80, "\012\001  --== Les Chemins de Galdeon ==--    ");
    printf ("\033J\033A--== Les Chemins de Galdeon ==--    "
    // printf (
    //     "\033J --== Les Chemins de Galdeon ==--\n"
    // "\033J --== Les Chemins de Galdeon ==--\n"
"    par Jean-Baptiste PERIN (2021)\n\n"
"Votre teleportation au coeur des cites"
"ennemies nous permet d'en declencher\n"
"l'explosion programmee.\n");
    printf ("Mais cette situation vous expose car \n"
"l'explosion est imminente et vous\n"
"ne devez pas rester.\n"
"Le temps est compte pour vous evader \n"
"par les chemins de Galdeon ...\n\n");
    printf ("Appuyer sur :\n\n"
"-\033D1\033G pour jouer au niveau Facile\n"
"-\033D2\033G pour jouer au niveau Moyen\n"
"-\033D3\033G pour jouer au niveau Difficile\n"
"-\033DC\033G pour afficher les credits\n"
"-\033DO\033G pour configurer les options\n\n");
setKeyboardConfig();
if (keybconfig==0) {
    printf ("Commandes de jeu:\n\n"
"\033DUP / DOWN \033G: Avancer / Reculer\n"
"\033DLEFT/RIGHT\033G: Tourner Gauche / Droite\n"
"\033DX / C     \033G: Decaler Gauche / Droite\n"
"\033DESC       \033G: Quitter");
} else if (keybconfig==1){
    printf ("Commandes de jeu:\n\n"
"\033DW / S\033G: Avancer / Reculer\n"
"\033DQ / E\033G: Tourner Gauche / Droite\n"
"\033DZ / D\033G: Decaler Gauche / Droite\n"
"\033DESC  \033G: Quitter");
} else if (keybconfig==2){
    printf ("Commandes de jeu:\n\n"
"\033DY / H\033G: Avancer / Reculer\n"
"\033DT / U\033G: Tourner Gauche / Droite\n"
"\033DG / J\033G: Decaler Gauche / Droite\n"
"\033DESC  \033G: Quitter");

    // poke(0xbbd1,10);
    // poke(0xbbf9,10);
}

}
void wanaContinue(){
    printf("Appuyer sur:\n\n");
    printf ("-\033DC\033G pour continuer,\n\n");
    printf ("-\033DESC\033G pour quitter.");
}
void bye() {
    text();cls();paper(7); ink(0);
    sprintf (0xBB80, "                                       ");
    printf (" Merci d'avoir joue avec \n\n"
    "    --== Les Chemins De Galdeon ==--\n\n"
    "    par Jean-Baptiste PERIN (2021)\n\n");
}
char  retry() {
    char c;
    
    do {
        CLS
        sprintf (0xBB80, "\012\001        --== MAUVAIS REVE ==--        ");
        printf ("\033J\033A      --== MAUVAIS REVE ==--        ");
        printf("\n\n\n\n");
        printf("Fichtre !!\n\nQuel horrible cauchemar vous venez de faire !\n\n");
        printf("Vous vous etiez assoupi et vous avez  reve que vous restiez bloque dans\nl'explosion\n\n");
        printf("Heureusement que tout cela n'etait\nqu'un mauvais reve.\n\n");
        printf("Prenez le temps de reprendre vos\nemotions puis appuyer sur\n\n");
        printf ("-\033DR\033G pour recommencer l'aventure,\n\n");
        printf ("-\033DESC\033G pour quitter.");
        c=get();
    } while ((c != 'R') && (c!= KEY_ESCAPE)); //&& (c!= KEY_ESCAPE)
    return c;
}

char  congrats() {

    char c;

    computeNewScore();

    CLS
    sprintf (0xBB80, "\012\001        --== FELICITATIONS ==--        ");
    printf ("\033J\033A      --== FELICITATIONS ==--        ");
    printf("\n\n\n\n");
    printf("Vous vous etes echappe en %d secondes.\n\n",tabLevelParam[currentIdxParam-2]- remaining_seconds);
    printf("Il ne restait plus que %d secondes\navant l'explosion.\n\n",remaining_seconds);

    if (game_level == 0)
        printf("Votre score au niveau FACILE\n");
    else if (game_level == 1)
        printf("Votre score au niveau MOYEN\n");
    else if (game_level == 2)
        printf("Votre score au niveau DIFFICILE\n");
    printf("est desormais de:\n\n   %d points\n\n\n\n\n", current_score);

    wanaContinue();
    while (((c=get()) != 'C') && (c!= KEY_ESCAPE));
    return c;
}