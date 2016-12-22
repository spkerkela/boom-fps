#include "entity.h"

entity_id create_entity(world *w) {
  entity_id id;
  for(id = 0; id < ENTITY_COUNT; id++) {
    if(w->mask[id] == COMPONENT_NONE) {
      return id;
    }
  }
}

void destroy_entity(world *w, entity_id id) {
  w->mask[id] = COMPONENT_NONE;
}
