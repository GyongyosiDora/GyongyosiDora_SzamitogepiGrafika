#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "light.h"

void init_scene(void);
void render_scene(const Camera* camera, const Light* light);

#endif