#include <stdio.h>
#include "platform.h"

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;

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
      SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 0xFF, 0xFF, 0xFF));
      SDL_UpdateWindowSurface(gWindow);
    }
  }
  return GAME_OK;
}

void close() {
  SDL_DestroyWindow(gWindow);
  SDL_Quit();
}
