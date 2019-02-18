SECTION rodata_user

PUBLIC _balloon_sprite

   defb @11111111, @00000000
   defb @11111111, @00000000
   defb @11111111, @00000000
   defb @11111111, @00000000
   defb @11111111, @00000000
   defb @11111111, @00000000
   defb @11111111, @00000000

; ASM source file created by SevenuP v1.20
; SevenuP (C) Copyright 2002-2006 by Jaime Tejedor Gomez, aka Metalbrain

;GRAPHIC DATA:
;Pixel Size:      ( 16,  24)
;Char Size:       (  2,   3)
;Sort Priorities: Mask, Char line, Y char, X char
;Data Outputted:  Gfx
;Interleave:      Sprite
;Mask:            Yes, before graphic

_balloon_sprite:

	DEFB	252,  3,128,126,  0,192,  0,128 ; Col1
	DEFB	  0,128,  0,128,  0,192,128, 64

	DEFB	128, 96,192, 49,224, 16,224, 24
	DEFB	240, 12,248,  7,252,  3,255,  0

	DEFB	255,  0,255,  0,255,  0,255,  0
	DEFB	254,  1,254,  1,252,  3,249,  6

	DEFB	255,  0,255,  0,255,  0,255,  0 ; null
	DEFB	255,  0,255,  0,255,  0,255,  0 ; null

	DEFB	 15,240,  3, 12,  1,  6,  0,  3 ; Col2
	DEFB	  0,  1,  0,  1,  0, 33,  0, 99

	DEFB	  1,198,  3,140, 15, 16, 31, 96
	DEFB	 63, 64,127,128,127,128,127,128

	DEFB	127,128,127,128,127,128,127,128
	DEFB	127,128,255,  0,255,  0,255,  0

	DEFB	255,  0,255,  0,255,  0,255,  0 ; null
	DEFB	255,  0,255,  0,255,  0,255,  0 ; null