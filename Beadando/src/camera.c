#include "camera.h"
#include <GL/glu.h>
#include <math.h>

#define DEG_TO_RAD 0.01745329251f

void init_camera(Camera* camera) {
    camera->x = 0.0f;
    camera->y = -3.0f;
    camera->z = 1.5f;

    camera->horizontal_angle = 90.0f;
    camera->vertical_angle = 0.0f;
}

void apply_camera(const Camera* camera) {
    float horizontal = camera->horizontal_angle * DEG_TO_RAD;
    float vertical = camera->vertical_angle * DEG_TO_RAD;

    float look_x = cosf(vertical) * cosf(horizontal);
    float look_y = cosf(vertical) * sinf(horizontal);
    float look_z = sinf(vertical);

    gluLookAt(
        camera->x,
        camera->y,
        camera->z,

        camera->x + look_x,
        camera->y + look_y,
        camera->z + look_z,

        0.0f,
        0.0f,
        1.0f
    );
}

void update_camera(Camera* camera, const App* app) {
    const float speed = 0.005f;

    float angle = camera->horizontal_angle * DEG_TO_RAD;

    float forward_x = cosf(angle);
    float forward_y = sinf(angle);
    float right_x = cosf(angle - 90.0f * DEG_TO_RAD);
    float right_y = sinf(angle - 90.0f * DEG_TO_RAD);

    if (app->key_w) {
        camera->x += forward_x * speed;
        camera->y += forward_y * speed;
    }

    if (app->key_s) {
        camera->x -= forward_x * speed;
        camera->y -= forward_y * speed;
    }

    if (app->key_a) {
        camera->x -= right_x * speed;
        camera->y -= right_y * speed;
    }

    if (app->key_d) {
        camera->x += right_x * speed;
        camera->y += right_y * speed;
    }

    if (camera->x < -4.7f) {
        camera->x = -4.7f;
    }

    if (camera->x > 4.7f) {
        camera->x = 4.7f;
    }

    if (camera->y < -4.7f) {
        camera->y = -4.7f;
    }

    if (camera->y > 4.7f) {
        camera->y = 4.7f;
    }
}

void rotate_camera(Camera* camera, float mouse_dx, float mouse_dy) {
    const float sensitivity = 0.1f;

    camera->horizontal_angle -= mouse_dx * sensitivity;
    camera->vertical_angle -= mouse_dy * sensitivity;

    if (camera->vertical_angle > 80.0f) {
        camera->vertical_angle = 80.0f;
    }

    if (camera->vertical_angle < -80.0f) {
        camera->vertical_angle = -80.0f;
    }
}