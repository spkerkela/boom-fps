#include <SDL2/SDL.h>
#include "game_loop.h"
#include <stdint.h>

void main_loop(Map m) {
  char quit = 0;
  SDL_Event e;

  World world;
  entity_id id;
  for(id = 0; id < ENTITY_COUNT; id++) {
    world.mask[id] = COMPONENT_NONE;
  }
  entity_id player_id = create_player(&world, 10, 10, 0);
  entity_id player_id2 = create_player(&world, 20, 30, 0);
  while (!quit) {
    while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
        quit = 1;
      }
    }
    draw(m);
    draw_system(&world);
    draw_end();
  }
}
