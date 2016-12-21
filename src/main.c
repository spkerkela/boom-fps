#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "platform.h"
#include "game_loop.h"

const double CIRCLE = M_PI * 2;

map create_map(uint32_t width, uint32_t height) {
  map m;
  uint32_t x, y;
  char* grid = calloc(width*height, sizeof(char));
  m.width = width;
  m.height = height;
  for(x = 0; x < width; ++x) {
    for(y = 0; y < height; ++y) {
      if(x == 0 || x == width - 1 || y == 0 || y == height - 1) {
        grid[x + (y * width)] = 1;
      } else {
        grid[x + (y * width)] = 0;
      }
    }
  }
  m.wall_grid = grid;
  return m;
}

player create_player(double x, double y, double direction) {
  player p;
  p.x = x;
  p.y = y;
  p.direction = direction;
  return p;
}

int main(int argc, char** argv) {
  if(initialize() != GAME_OK) {
    printf("ERROR INITIALIZING\n");
    return 1;
  } else {
    main_loop(create_map(100, 200), create_player(1.0, 1.0, 0.0));
    close();
    return 0;
  }
}


