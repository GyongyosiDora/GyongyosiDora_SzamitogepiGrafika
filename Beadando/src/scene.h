#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "light.h"
#include "model.h"
#include <stdbool.h>

typedef struct {
    Model body;
    Model lid;
    bool is_open;
    float lid_angle;
} Chest;

typedef struct Scene {
    Model torch;
    Chest chest;
} Scene;

int init_scene(Scene* scene);
void render_scene(const Scene* scene, const Camera* camera, const Light* light);
void destroy_scene(Scene* scene);
void update_scene(Scene* scene, const App* app);

#endif