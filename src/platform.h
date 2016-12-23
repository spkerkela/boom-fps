#ifndef _INITIALIZE_H_
#define _INITIALIZE_H_

#include <SDL2/SDL.h>
#include "game.h"

game_error initialize();
void close();
void draw(Map);
void draw_point(uint32_t x, uint32_t y);
void draw_end();

#else
#endif
