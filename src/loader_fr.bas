
5 PRINT@3,24;"Chargement ..."

10 HIRES
;; 15 GET K$
;; 19 GET K$
20 POKE #BF68, 16: POKE #BF69, 7
30 POKE #BF90, 16: POKE #BF91, 7
40 POKE #BFB8, 16: POKE #BFB9, 7
70 POKE #BF70, ASC("C")
75 POKE #BF71, ASC("H")
80 POKE #BF72, ASC("A")
85 POKE #BF73, ASC("R")
90 POKE #BF74, ASC("G")
95 POKE #BF75, ASC("E")
100 POKE #BF76, ASC("M")
105 POKE #BF77, ASC("E")
110 POKE #BF78, ASC("N")
120 POKE #BF79, ASC("T")
120 POKE #BF7A, ASC(".")
120 POKE #BF7B, ASC(".")
120 POKE #BF7C, ASC(".")
200 CLOAD"
300 CLOAD"
400 CLOAD"