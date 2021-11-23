#ifndef __GUIRUBIKSCUBE__H__
#define __GUIRUBIKSCUBE__H__
#include <SDL.H>
#include <stdio.h>
#include <stdlib.h>
#define PADDING 20
#define HEIGHT_SQUARE 10
#define HEIGHT_WINDOW HEIGHT_SQUARE * 12 + PADDING
#define WIDTH_WINDOW HEIGHT_SQUARE*12 + PADDING
extern void void init(Cube *);
#endif  //!__GUIRUBIKSCUBE__H__