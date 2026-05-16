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

void update_camera(Camera* camera, const App* app) {
    const float speed = 0.05f;

    if (app->key_w) {
        camera->z -= speed;
    }

    if (app->key_s) {
        camera->z += speed;
    }

    if (app->key_a) {
        camera->x -= speed;
    }

    if (app->key_d) {
        camera->x += speed;
    }
}