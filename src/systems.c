#include "systems.h"

#define DRAW_MASK (COMPONENT_POSITION | COMPONENT_APPEARANCE)

void draw_system(World *w) {
  entity_id id;
  for(id = 0; id < ENTITY_COUNT; id++) {
    if((w->mask[id] & DRAW_MASK) == DRAW_MASK) {
      Position p = w->pos[id];
      printf("draw %d %s\n", id, w->appearance[id].name);
      printf("position is %f %f %f\n", p.x, p.y, p.direction);
    }
  }
}
