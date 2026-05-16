#ifndef CAMERA_H
#define CAMERA_H

#include "app.h"

typedef struct Camera {
    float x;
    float y;
    float z;

    float horizontal_angle;
    float vertical_angle;
} Camera;

void init_camera(Camera* camera);
void apply_camera(const Camera* camera);
void update_camera(Camera* camera, const App* app);
void rotate_camera(Camera* camera, float mouse_dx, float mouse_dy);

#endif