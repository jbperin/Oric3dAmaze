void myHires() {
    
    asm(
        // Set status to indicate hires mode.
        "LDA $02C0;" 
        "ORA #$01;"
        "STA $02C0;" 
    );
    
    // asm(
    //     // Copy Character sets from B400 -> BB80 to 9800 -> 9f80
    //     "LDX #$0B;" 
    //     "JSR $F982;"
    // );

    asm(
        // Disable cursor.
        "LDA #$FE ;"
        "AND $026A;"
        "STA $026A;"
        // Write 50Hz attribute to last location on screen.
        "LDA #$1E ;"
        "STA $BFDF;"
        "LDA #$40 ;"
        "STA $A000;"
    );

    // asm(
    //     // Copy 7999 bytes from A000 to A001 (clear hires screen)
    //     "LDX #$17;" 
    //     "JSR $F982;"
    // );

    asm(
        // Set X and Y cursor coordinates to zero.
        "LDA #$00;" 
        "STA $0219;"
        "STA $021A;"
        // Set cursor address to #A000.
        "STA $10;"  
        "LDA #$A0;" 
        "STA $11;" 
        // Set cursor position within byte on screen.
        "LDA #$20;" 
        "STA $0215;"
        // Set pattern register.
        "LDA #$FF;" 
        "STA $0213;"
        //"JSR $F8DC;"
    );


// SET UP PAGE 2 VARIABLES
    asm(
        //Set hires indicator.
        "LDA $01;"
        "LDA $021F;"

        // Set the address of the first 
        // line of text section of screen 
        // to $BF68 and that of the 
        // second line to $BF90. 
        "LDA #$BF;" 
        "STA $027B;"
        "STA $0279;"
        "LDA #$68;" 
        "STA $027A;"
        "LDA #$90;" 
        "STA $0278;"

        // Set the maximum number of rows of text available.
        "LDA #$03;" 
        "STA $027E;"

        //Set number of characters used
        // in screen scrolling to 80 - 
        // two lines worth. 
        "LDA #$00;" 
        "STA $027D;"
        "LDA #$50;" 
        "STA $027C;"

        // Clear Screen
        "LDA #$0C;" 
        "JSR $0238;" // "JSR $F77C;"			
	);


    asm(
        // Re-enable cursor.
        "LDA #$01;" 
        "ORA $026A;"
        "STA $026A;"
    );

}