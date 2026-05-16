#ifndef CAMERA_H
#define CAMERA_H

#include "app.h"

typedef struct Camera {
    float x;
    float y;
    float z;
} Camera;

void init_camera(Camera* camera);
void apply_camera(const Camera* camera);
void update_camera(Camera* camera, const App* app);

#endif