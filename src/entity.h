#ifndef ENTITY_H
#define ENTITY_H

static const int ENTITY_COUNT = 200;

typedef uint32_t entity_id;

typedef char* component_name;

typedef enum {
  COMPONENT_NONE = 0,
  COMPONENT_POSITION = 1 << 0,
  COMPONENT_APPEARANCE = 1 << 1,
} component;

typedef struct {
  float x, y;
} position;

typedef struct {
  entity_id mask[ENTITY_COUNT];
  position pos[ENTITY_COUNT];
} world;

entity_id create_entity(world *w);
void destroy_entity(world *w, entity_id);

#endif
