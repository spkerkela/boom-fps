#include "entity.h"

entity_id create_entity(World *w) {
  entity_id id;
  for(id = 0; id < ENTITY_COUNT; id++) {
    if(w->mask[id] == COMPONENT_NONE) {
      return id;
    }
  }
  return ENTITY_COUNT;
}

void destroy_entity(World *w, entity_id id) {
  w->mask[id] = COMPONENT_NONE;
}

entity_id create_player(World *w, double x, double y, double direction) {
  entity_id id = create_entity(w);
  w->mask[id] = COMPONENT_POSITION | COMPONENT_APPEARANCE;
  w->pos[id].x = x;
  w->pos[id].y = y;
  w->pos[id].direction = direction;
  w->appearance[id].name = "player";
  return id;
}
