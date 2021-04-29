

#include "keyboard_c.c"


#define CLS text();cls();poke (0xBBA3, CHANGE_INK_TO_BLACK);poke(0x26A, (mode0 | 0x08) & 0xFE);

void waitkey () {
    // "Appuyez sur une touche ..."
    sprintf (0xBF70, "Pulsar una tecla ...");
    get();
}

void mmiInit(){
    sprintf (message, "Tiempo restante"); // "Temps restant:"
    AdvancedPrint(1,26, message);
}
void credits(){

    CLS
    sprintf (0xBB80, "\012\001  --== Los caminos de Galdeon ==--    ");
    printf ("\033J\033A--== Los caminos de Galdeon ==--    "
    "\n                            v 1.0\n"
    "\033C   Creado y desarrollado por: \n\n"
    "       Jean-Baptiste PERIN (JiBe)\n\n"
    "\033C   aconseja por: \n\n"
    "        Mickael POINTIER (Dbug)\n\n"
    "        Vincent BILLET (Xaratheus)\n");
    printf("\n\033CCon contribuciones de:\n"
"Chema, Dbug, Twiligthe (keyboard)\n"
"\n\033CY el benevolente estimulo de:\n"
"Badger, didierV, gotcha, ibisum, iss, jede, kenneth, Magoric,  Neotenien,\nrax, sam, SteveM, Symoon, ThomH,\nxahmol\n"
    );
    printf("\n\033CEste juego usa castoric para 3D\n\n"
    "\033Dgithub.com/oric-software/castoric\033C\n"
    " ---------------------------------\n"
    );
    get();
}
void setKeyboard(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== AJUSTE DEL TECLADO ==--    ");
    printf ("\033J\033A   --== AJUSTE DEL TECLADO ==--    "
        "\n\n"
        "\033CSeleccione su configuracion\n"
        "\033C   teclado preferido presionando \n"
        "\033C   tecla 1, 2 o 3:\n");

        printf ("\n\033D[1]\033C: \n\n"
        " LEFT/RIGHT : girar izquierda/derecha\n"
        " UP/DOWN    : avanzar / retroceder\n"
        " X / C : desplazarse izquierda/derecha\n");

        printf ("\n\033D[2]\033C: \n\n"

        " Q / E : girar izquierda/derecha\n"
        " W / S : avanzar / retroceder\n"
        " Z / D : desplazarse izquierda/derecha\n");

        printf ("\n\033D[3]\033C: \n\n"
        " T / U : girar izquierda/derecha\n"
        " Y / H : avanzar / retroceder\n"
        " G / J : desplazarse izquierda/derecha\n" );
    } while (((c=get()) != '1') && (c != '2') && (c != '3'));
    keybconfig = c-'1';
    setKeyboardConfig();
}

void setSound(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== AJUSTE DE SONIDOS ==--    ");
    printf ("\033J\033A   --== AJUSTE DE SONIDOS ==--    "
        "\n\n"
        " \033D[1]\033C: suena mal\n\n"
        " \033D[2]\033C: sonidos activos\n\n"
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
    sprintf (0xBB80, "\012\001  --== Los caminos de Galdeon ==--    ");
    printf ("\033J\033A--== Los caminos de Galdeon ==--    "
"     de Jean-Baptiste PERIN (2021)\n\n"
// "Votre teleportation au coeur des cites"
// "ennemies nous permet d'en declencher\n"
// "l'explosion programmee.\n");
  "Tu teletransportacion al corazon de\n"
  "las ciudades enemigos nos permite \n"
  "activarlos la explosion programada."
);
    printf (
   "\nPero esta situacion te expone porque\n"
   "la explosion es inminente y tu no debe"
   "quedarse.\n"
   "El tiempo es esencial para alejarse de"
   "todo por los caminos de Galdeon ...\n"
    );

    printf ("Apoyar sobre :\n\n"
"-\033D1\033C para jugar en el nivel Facil\n"
"-\033D2\033C para jugar en el nivel Medio\n"
"-\033D3\033C para jugar en el nivel Dificil\n"
"-\033DC\033C para mostrar los creditos\n"
"-\033DO\033C para configurar opciones\n\n");
setKeyboardConfig();
if (keybconfig==0) {
    printf ("Controles del juego:\n\n"
"\033DUP / DOWN \033C: Avanzar / Retroceder\n"
"\033DLEFT/RIGHT\033C: Girar Izquierda/Derecha\n"
"\033DX / C \033C: Desplazar Izquierda/Derecha\n"
"\033DESC       \033C: Salir");
} else if (keybconfig==1){
    printf ("Controles del juego:\n\n"
"\033DW / S\033C: Avanzar / Retroceder\n"
"\033DQ / E\033C: Girar Izquierda / Derecha\n"
"\033DZ / D\033C: Desplazar Izquierda / Derecha\n"
"\033DESC  \033C: Salir");
} else if (keybconfig==2){
    printf ("Controles del juego:\n\n"
"\033DY / H\033C: Avanzar / Retroceder\n"
"\033DT / U\033C: Girar Izquierda / Derecha\n"
"\033DG / J\033C: Desplazar Izquierda / Derecha\n"
"\033DESC  \033C: Salir");

    // poke(0xbbd1,10);
    // poke(0xbbf9,10);
}

}
void wanaContinue(){
    printf("Pulse la tecla:\n\n");
    printf ("-\033DC\033C para continuar,\n\n");
    printf ("-\033DESC\033C para salir.");
}
void bye() {
    text();cls();paper(7); ink(0);
    sprintf (0xBB80, "                                       ");
    printf (" Gracias por jugar con \n\n"
    "    --== Los caminos de Galdeon ==--\n\n"
    "     de Jean-Baptiste PERIN (2021)\n\n");
}
char  retry() {
    char c;
    
    do {
        CLS
        sprintf (0xBB80, "\012\001        --== MAL SUENO ==--        ");
        printf ("\033J\033A      --== MAL SUENO ==--        ");
        printf("\n\n\n\n");
        printf("Maldita sea !!\n\nDe que horrible pesadilla vienes hacer!\n\n");
        printf("Te quedaste dormido y sonaste que estabas atrapado en la explosion\n\n");
        // printf("Heureusement que tout cela n'etait\nqu'un mauvais reve.\n\n");
        printf("Afortunadamente, todo esto fue solo\nuna pesadilla.\n\n");
        // printf("Prenez le temps de reprendre vos\nemotions puis appuyer sur\n\n");
        printf("Tomese el tiempo para volver a sus\nsentidos y luego presione la tecla\n\n");
        printf ("-\033DR\033C para reiniciar la aventura,\n\n");
        printf ("-\033DESC\033C para salir.");
        c=get();
    } while ((c != 'R') && (c!= KEY_ESCAPE)); //&& (c!= KEY_ESCAPE)
    return c;
}

char  congrats() {

    char c;

    computeNewScore();

    CLS
    sprintf (0xBB80, "\012\001        --== FELICITACIONES ==--      ");
    printf ("\033J\033A      --== FELICITACIONES ==--      ");
    printf("\n\n\n\n");
    printf("Escapaste en %d segundos.\n\n",tabLevelParam[currentIdxParam-2]- remaining_seconds);
    printf("Solo quedaban %d segundos\nantes de la explosion.\n\n",remaining_seconds);

    if (game_level == 0)
        printf("Tu puntuacion en el nivel FACIL\n");
    else if (game_level == 1)
        printf("Tu puntuacion en el nivel MEDIO\n");
    else if (game_level == 2)
        printf("Tu puntuacion en el nivel DIFICIL\n");
    printf("es ahora:\n\n   %d puntos\n\n\n\n\n", current_score);

    wanaContinue();
    while (((c=get()) != 'C') && (c!= KEY_ESCAPE));
    return c;
}