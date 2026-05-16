#include "camera.h"
#include <GL/gl.h>

void init_camera(Camera* camera) {
    camera->x = 0.0f;
    camera->y = 0.0f;
    camera->z = 6.0f;
}

void apply_camera(const Camera*camera) {
    glTranslatef(-camera->x, -camera->y, -camera->z);
}