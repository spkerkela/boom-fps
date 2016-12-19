#include <SDL2/SDL.h>
#include "game_loop.h"
#include <stdint.h>

void main_loop() {
  char quit = 0;
  SDL_Event e;

  while (!quit) {
    while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
        quit = 1;
      } else {
        draw();
      }
    }
  }
}
