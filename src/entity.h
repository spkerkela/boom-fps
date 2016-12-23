#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

static const int ENTITY_COUNT = 200;

typedef uint32_t entity_id;

typedef char* component_name;

typedef enum {
  COMPONENT_NONE = 0,
  COMPONENT_POSITION = 1 << 0,
  COMPONENT_APPEARANCE = 1 << 1,
} Component;

typedef struct {
  char* name;
} Appearance;

typedef struct {
  uint32_t x, y, direction;
} Position;

typedef struct {
  entity_id mask[ENTITY_COUNT];
  Position pos[ENTITY_COUNT];
  Appearance appearance[ENTITY_COUNT];
} World;

entity_id create_entity(World *w);
entity_id create_player(World *w, double x, double y, double direction);
void destroy_entity(World *w, entity_id);

#endif
