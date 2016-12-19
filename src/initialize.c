#include <stdio.h>
#include "initialize.h"

int other_func(char* in) {
  printf("%s\n", in);
  return 32;
}

game_error initialize() {
  return GAME_OK;
}
