
;; Autogenerated file. Do not modify by hand.
;; Use script clearColumn.py
;; [ref config_viewport] 
#include "config.h"
#ifndef  USE_C_VIEWPORT
_clearColumn
    lda _idxScreenCol
    lsr
    tax 
patch_red_in_sky:lda #$40	; pixel eteint
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 0),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 3),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 6),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 9),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 12),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 15),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 18),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 21),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 24),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 27),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 30),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 33),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 36),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 39),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 42),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 45),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 48),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 51),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 54),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 57),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 60),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 63),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 66),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 69),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 72),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 75),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 78),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 81),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 84),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 87),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 90),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 93),x
patch_green_in_sky:lda #$40	; pixel eteint
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 1),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 4),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 7),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 10),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 13),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 16),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 19),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 22),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 25),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 28),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 31),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 34),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 37),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 40),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 43),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 46),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 49),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 52),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 55),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 58),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 61),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 64),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 67),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 70),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 73),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 76),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 79),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 82),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 85),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 88),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 91),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 94),x
patch_blue_in_sky:lda #$7F	; pixel allume
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 2),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 5),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 8),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 11),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 14),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 17),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 20),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 23),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 26),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 29),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 32),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 35),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 38),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 41),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 44),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 47),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 50),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 53),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 56),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 59),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 62),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 65),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 68),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 71),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 74),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 77),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 80),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 83),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 86),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 89),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 92),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 95),x
patch_red_on_ground:lda #$40	; pixel eteint
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 96),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 99),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 102),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 105),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 108),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 111),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 114),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 117),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 120),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 123),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 126),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 129),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 132),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 135),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 138),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 141),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 144),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 147),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 150),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 153),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 156),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 159),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 162),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 165),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 168),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 171),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 174),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 177),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 180),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 183),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 186),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 189),x
patch_green_on_ground:lda #$7F	; pixel allume
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 97),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 100),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 103),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 106),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 109),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 112),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 115),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 118),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 121),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 124),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 127),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 130),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 133),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 136),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 139),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 142),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 145),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 148),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 151),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 154),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 157),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 160),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 163),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 166),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 169),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 172),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 175),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 178),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 181),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 184),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 187),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 190),x
patch_blue_on_ground:lda #$40	; pixel eteint
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 98),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 101),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 104),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 107),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 110),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 113),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 116),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 119),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 122),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 125),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 128),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 131),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 134),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 137),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 140),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 143),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 146),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 149),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 152),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 155),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 158),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 161),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 164),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 167),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 170),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 173),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 176),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 179),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 182),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 185),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 188),x
sta HIRES_SCREEN_ADDRESS + VIEWPORT_START_COLUMN/2 + NEXT_SCANLINE_INCREMENT * ( VIEWPORT_START_LINE*3 + 191),x


clearColumnDone    

	rts
#endif // USE_C_VIEWPORT

