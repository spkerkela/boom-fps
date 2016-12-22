#include <stdio.h>
#include "platform.h"

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

const uint32_t TILE_SIZE = 12;

game_error log_SDL_error() {
  printf("SDL Error %s\n", SDL_GetError());
  return GAME_GRAPHICS_ERROR;
}

game_error initialize() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return log_SDL_error();
  } else {
    gWindow = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
    if (gWindow == NULL) {
      return log_SDL_error();
    } else {
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }
  return GAME_OK;
}

void close() {
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
}

void draw(Map game_map, Player p) {
  int x, y;
  SDL_Rect rect;
  rect.w = TILE_SIZE;
  rect.h = TILE_SIZE;
  SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));
  for(x = 0; x < game_map.width; ++x) {
    for(y = 0; y < game_map.height; ++y) {
      rect.x = x * TILE_SIZE;
      rect.y = y * TILE_SIZE;
      if(game_map.wall_grid[x + (y * game_map.width)] == 0) {
        SDL_FillRect(gScreenSurface, &rect, SDL_MapRGB(gScreenSurface->format, 0x01, 0xFF, 0x01));
      } else {
        SDL_FillRect(gScreenSurface, &rect, SDL_MapRGB(gScreenSurface->format, 0xCC, 0xCC, 0xCC));
      }
    }
  }
  SDL_UpdateWindowSurface(gWindow);
}
