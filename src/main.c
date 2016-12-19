#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "platform.h"
#include "game_loop.h"

const double CIRCLE = M_PI * 2;
int main(int argc, char** argv) {
  if(initialize() != GAME_OK) {
    printf("ERROR INITIALIZING\n");
    return 1;
  } else {
    main_loop();
    close();
    return 0;
  }
}


