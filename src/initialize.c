#include <stdio.h>
#include "initialize.h"

game_error log_SDL_error() {
  printf("SDL Error %s\n", SDL_GetError());
  return GAME_GRAPHICS_ERROR;
}

game_error initialize() {
  SDL_Window* window = NULL;
  SDL_Surface* screenSurface = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return log_SDL_error();
  } else {
    window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL);
    if (window == NULL) {
      return log_SDL_error();
    } else {
      screenSurface = SDL_GetWindowSurface(window);
      SDL_FillRect(screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ));
      SDL_UpdateWindowSurface(window);
      SDL_Delay(2000);
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return GAME_OK;
}
