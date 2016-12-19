#ifndef _GAME_H_
#define _GAME_H_

typedef enum {
  GAME_OK,
  GAME_ERROR,
  GAME_GRAPHICS_ERROR,
  GAME_ERROR_COUNT
} game_error;

static const int GAME_SCREEN_WIDTH = 640;
static const int GAME_SCREEN_HEIGHT = 480;
static const char* GAME_TITLE = "Game";

#endif
