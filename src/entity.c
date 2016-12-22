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
