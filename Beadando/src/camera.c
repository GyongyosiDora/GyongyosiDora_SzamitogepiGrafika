#include "camera.h"
#include <GL/gl.h>

void init_camera(Camera* camera) {
    camera->x = 0.0f;
    camera->y = 0.0f;
    camera->z = 6.0f;

    camera->horizontal_angle = 0.0f;
    camera->vertical_angle = 0.0f;
}

void apply_camera(const Camera*camera) {
    glRotatef(-camera->vertical_angle, 1.0f, 0.0f, 0.0f);
    glRotatef(-camera->horizontal_angle, 0.0f, 1.0f, 0.0f);
    
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

void rotate_camera(Camera* camera, float mouse_dx, float mouse_dy) {
    const float sensitivity = 0.1f;

    camera->horizontal_angle += mouse_dx * sensitivity;
    camera->vertical_angle += mouse_dy * sensitivity;

    if (camera->vertical_angle > 89.0f) {
        camera->vertical_angle = 89.0f;
    }

    if (camera->vertical_angle < -89.0f) {
        camera->vertical_angle = -89.0f;
    }
}