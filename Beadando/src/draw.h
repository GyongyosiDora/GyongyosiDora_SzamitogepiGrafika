#ifndef ROOM_H
#define ROOM_H

#include "model.h"
#include "light.h"

void draw_room(unsigned int wall_tex, unsigned int floor_tex);

// modellek
void draw_torch(const Model* model, const Light* light);
void draw_table(void);
void draw_chest(const Model* body, const Model* lid, float lid_angle, unsigned int body_tex, unsigned int lid_tex);

#endif