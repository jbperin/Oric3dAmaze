

#include "keyboard_c.c"

#define CLS text();cls();poke (0xBBA3, CHANGE_INK_TO_BLACK);poke(0x26A, (mode0 | 0x08) & 0xFE);


void waitkey () {
    sprintf (0xBF70, "Premere un tasto ...");
    get();
}

void mmiInit(){
    sprintf (message, "Tempo rimanente:");
    AdvancedPrint(1,26, message);
}
void credits(){

    CLS
    sprintf (0xBB80, "\012\001  --== I sentieri di Galdeon ==--     ");
    printf ("\033J\033A--== I sentieri di Galdeon ==--    "
    "\n                            v 1.0\n"
    "\033B   Creato e sviluppato da: \n\n"
    "       Jean-Baptiste PERIN (JiBe)\n\n"
    "\033B   consigliato da: \n\n"
    "        Mickael POINTIER (Dbug)\n\n"
    "        Vincent BILLET (Xaratheus)\n");
    printf("\n\033Bcon la partecipazione di:\n"
"Chema, Dbug, Twiligthe (keyboard)\n"
"\n\033Be l'incoraggiamento benevolo di:\n"
"Badger, didierV, gotcha, ibisum, iss, jede, kenneth, Magoric,  Neotenien,\nrax, sam, SteveM, Symoon, ThomH,\nxahmol\n"
    );
    printf("\nQuesto gioco utilizza castoric per il 3D\n\n"
    "\033Dgithub.com/oric-software/castoric\033B\n"
    " ---------------------------------\n"
    );
    get();
}
void setKeyboard(){
    char c;
    do {
        CLS
sprintf (0xBB80, "\012\001     --== IMPOSTAZIONI TASTERIA ==--  ");
    printf ("\033J\033A   --== IMPOSTAZIONI TASTERIA ==--  "
        "\n\n"
        "Selezionare la configurazione della\n"
        "  tastiera preferita premendo \n"
        "    sul tasto 1, 2 o 3:\n");

        printf ("\n\033D[1]\033B: \n\n"
        "  LEFT/RIGHT: girare a sinistra/destra"
        "  UP/DOWN   : avanti / indietro\n"
        "  X / C     : decaler sinistra/destra\n");

        printf ("\n\033D[2]\033B: \n\n"

        "  Q / E : girare a sinistra / destra\n"
        "  W / S : avanti / indietro\n"
        "  Z / D : decaler sinistra / destra\n");

        printf ("\n\033D[3]\033B: \n\n"
        "  T / U : girare a sinistra / destra\n"
        "  Y / H : avanti / indietro\n"
        "  G / J : decaler sinistra / destra\n"        );
    } while (((c=get()) != '1') && (c != '2') && (c != '3'));
    keybconfig = c-'1';
    setKeyboardConfig();
}

void setSound(){
    char c;
    do {
        CLS
    sprintf (0xBB80, "\012\001     --== IMPOSTAZIONI AUDIO ==--  ");
    printf ("\033J\033A   --== IMPOSTAZIONI AUDIO ==--  "
        "\n\n"
        " \033D[1]\033B: Suona spento\n\n"
        " \033D[2]\033B: Suoni attivati\n\n"
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
    sprintf (0xBB80, "\012\001  --== I sentieri di Galdeon ==--     ");
    printf ("\033J\033A--== I sentieri di Galdeon ==--     "
    // printf (
    //     "\033J --== Les Chemins de Galdeon ==--\n"
    // "\033J --== Les Chemins de Galdeon ==--\n"
"    da Jean-Baptiste PERIN (2021)\n\n"
"Il tuo teletrasporto nel cuore delle\n"
"citta nemiche ci permette di innescare"
"la loro esplosione programmata.\n");
    printf ("Ma questa situazione ti espone perche\n"
"l'esplosione e imminente e non devi\n"
"rimanere.\n"
"Il tempo sta per scadere per sfuggire\n"
"ai sentieri di Galdeon ...\n\n");
    printf ("Premere :\n\n"
"-\033D1\033B per giocare a livello Facile\n"
"-\033D2\033B per giocare a livello Medio\n"
"-\033D3\033B per giocare a livello Difficile\n"
"-\033DC\033B per visualizzare i crediti\n"
"-\033DO\033B per configurare le opzioni\n\n");
setKeyboardConfig();
if (keybconfig==0) {
    printf ("Controlli di gioco:\n\n"
"\033DUP / DOWN \033B: avanti / indietro\n"
"\033DLEFT/RIGHT\033B: girare a sinistra/destra"
"\033DX / C     \033B: decaler sinistra/destra\n"
"\033DESC       \033B: Lasciare");
} else if (keybconfig==1){
    printf ("Controlli di gioco:\n\n"
"\033DW / S\033B: avanti / indietro\n"
"\033DQ / E\033B: girare a sinistra/destra\n"
"\033DZ / D\033B: decaler sinistra/destra\n"
"\033DESC  \033B: Lasciare");
} else if (keybconfig==2){
    printf ("Controlli di gioco:\n\n"
"\033DY / H\033B: avanti / indietro\n"
"\033DT / U\033B: girare a sinistra/destra\n"
"\033DG / J\033B: decaler sinistra/destra\n"
"\033DESC  \033B: Lasciare");

    // poke(0xbbd1,10);
    // poke(0xbbf9,10);
}

}
void wanaContinue(){
    printf("Premere :\n\n");
    printf ("-\033DC\033B per continuare,\n\n");
    printf ("-\033DESC\033B per lasciare.");
}
void bye() {
    text();cls();paper(7); ink(0);
    sprintf (0xBB80, "                                       ");
    printf (" Grazie per aver giocato con \n\n"
    "    --== I sentieri di Galdeon ==--\n\n"
    "    da Jean-Baptiste PERIN (2021)\n\n");
}
char  retry() {
    char c;
    
    do {
        CLS
        sprintf (0xBB80, "\012\001        --== BRUTO SOGNO ==--         ");
        printf ("\033J\033A      --== BRUTO SOGNO ==--         ");
        printf("\n\n\n\n");
        printf("Fichtre !!\n\nChe incubo orribile che hai appena\nfatto !\n\n");
        printf("Ti sei assopito e hai sognato di\nessere rimasto bloccato\nnell'esplosione\n\n");
        printf("Fortunatamente, tutto questo era solo un brutto sogno.\n\n");
        printf("Prendetevi il tempo per venire\nai vostri sensi e quindi premere\n\n");
        printf ("-\033DR\033B per ricominciare l'avventura,\n\n");
        printf ("-\033DESC\033B per lasciare.");
        c=get();
    } while ((c != 'R') && (c!= KEY_ESCAPE)); //&& (c!= KEY_ESCAPE)
    return c;
}

char  congrats() {

    char c;

    computeNewScore();

    CLS
    sprintf (0xBB80, "\012\001        --== KUDOS ==--                ");
    printf ("\033J\033A      --== KUDOS ==--                ");
    printf("\n\n\n\n");
    printf("Sei scappato in  %d secondi.\n\n",tabLevelParam[currentIdxParam-2]- remaining_seconds);
    printf("Erano rimasti solo %d secondi\nprima dell'esplosione.\n\n",remaining_seconds);

    if (game_level == 0)
        printf("Il tuo punteggio a livello FACILE\n");
    else if (game_level == 1)
        printf("Il tuo punteggio a livello MEDIO\n");
    else if (game_level == 2)
        printf("Il tuo punteggio a livello DIFFICILE\n");
    printf("e ora di :\n\n   %d punti\n\n\n\n\n", current_score);

    wanaContinue();
    while (((c=get()) != 'C') && (c!= KEY_ESCAPE));
    return c;
}