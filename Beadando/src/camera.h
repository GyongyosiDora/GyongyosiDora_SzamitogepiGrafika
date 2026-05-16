#ifndef CAMERA_H
#define CAMERA_H

typedef struct Camera {
    float x;
    float y;
    float z;
} Camera;

void init_camera(Camera* camera);
void apply_camera(const Camera* camera);

#endif