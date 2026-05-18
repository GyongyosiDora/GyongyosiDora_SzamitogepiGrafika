#ifndef LIGHT_H
#define LIGHT_H

#include "app.h"
#include "camera.h"

typedef struct Light {
    float intensity;
} Light;

void init_light(Light* light);
void update_light(Light* light, const App* app);
void apply_light(const Light* light, const Camera* camera);

#endif