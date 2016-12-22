#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "platform.h"
#include "game_loop.h"

const double CIRCLE = M_PI * 2;


Map create_map(uint32_t width, uint32_t height) {
  Map m;
  uint32_t x, y;
  char* grid = calloc(width*height, sizeof(char));
  m.width = width;
  m.height = height;
  for(x = 0; x < width; ++x) {
    for(y = 0; y < height; ++y) {
      if(x == 0 || x == width - 1 || y == 0 || y == height - 1) {
        grid[x + (y * width)] = 1;
      } else {
        if(rand() % 2 == 0) {
          grid[x + (y * width)] = 1;
        } else {
          grid[x + (y * width)] = 0;
        }
      }
    }
  }
  m.wall_grid = grid;
  return m;
}

Player create_player(double x, double y, double direction) {
  Player p;
  p.x = x;
  p.y = y;
  p.direction = direction;
  return p;
}

int main(int argc, char** argv) {
  srand(time(NULL));
  if(initialize() != GAME_OK) {
    printf("ERROR INITIALIZING\n");
    return 1;
  } else {
    main_loop(create_map(100, 200), create_player(1.0, 1.0, 0.0));
    close();
    return 0;
  }
}


