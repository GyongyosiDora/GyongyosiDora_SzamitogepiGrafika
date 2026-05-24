#ifndef ROOM_H
#define ROOM_H

#include "model.h"
#include "light.h"

void draw_room(void);
void draw_test_box(void);

// modellek
void draw_torch(const Model* model, const Light* light);
void draw_table(void);
void draw_chest(const Model* body, const Model* lid, float lid_angle);

#endif