#pragma output REGISTER_SP = 0xD000

#include <z80.h>
#include <arch/zx.h>
#include <arch/zx/sp1.h>
#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>

extern unsigned char balloon_sprite[];

struct sp1_Rect full_screen = {0, 0, 32, 24};

#define MAX_SPRITES 15

struct sprballoons
{
  struct sp1_ss     *s; // current sprite
  char               y; // ypos
  char               x; // xpos
  char              dx; // speed
  char           color; // color
} sprballoons[MAX_SPRITES];


static int sprite_col;
void initialiseColour(unsigned int count, struct sp1_cs *c)
{
  (void)count; // ref

  c->attr_mask = SP1_AMASK_INK;
  c->attr = sprite_col;
}

int main()
{
  // srand(rand_timer); // Seed random

  struct sp1_ss  *s;
  // unsigned char x;
  // unsigned char y;
  unsigned char i;

  zx_border(INK_BLACK);

  sp1_Initialize( SP1_IFLAG_MAKE_ROTTBL | SP1_IFLAG_OVERWRITE_TILES | SP1_IFLAG_OVERWRITE_DFILE,
                  INK_BLACK | PAPER_WHITE,
                  ' ' );
  sp1_Invalidate(&full_screen);

   for (i=0; i!=MAX_SPRITES; ++i)
   {
     s = sprballoons[i].s = sp1_CreateSpr(SP1_DRAW_MASK2LB, SP1_TYPE_2BYTE, 4, 0, i);
     sp1_AddColSpr(s, SP1_DRAW_MASK2, SP1_TYPE_2BYTE, 64, i); // Offset of 64 bytes for 2nd col
     sp1_AddColSpr(s, SP1_DRAW_MASK2RB, SP1_TYPE_2BYTE, 0, i);

     sprballoons[i].y = rand() % 192; // random seed of y position.
     sprballoons[i].x = rand() % 255; // random seed of x position.
     sprballoons[i].dx = rand() % 5 + 1; //  speed of x.
     sprballoons[i].color = INK_BLUE + (rand() % 4); // set one of four colours.
   }


  while(1)
  {
    for(i=0; i!=MAX_SPRITES; ++i)
    {
      sprballoons[i].x += sprballoons[i].dx;

      sp1_MoveSprPix(sprballoons[i].s, &full_screen, balloon_sprite,
        sprballoons[i].x, sprballoons[i].y); // Well that's bollocks

      sprballoons[i].x = sprballoons[i].x % 255; // Rollover

      sprite_col = sprballoons[i].color;
      sp1_IterateSprChar(sprballoons[i].s, initialiseColour);
    }

    z80_delay_ms(20);
    sp1_UpdateNow();
  }
}