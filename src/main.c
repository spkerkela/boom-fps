#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#include "initialize.h"

const double CIRCLE = M_PI * 2;
int main(int argc, char** argv) {
    printf("%s\n", "Hello, BOOM!");
    printf("%s\n", argv[0]);
    printf("%f\n", CIRCLE);
    uint32_t n = other_func("sd");
    printf("%d\n", n);
    return 0;
}


