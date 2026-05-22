#include "light.h"
#include <GL/gl.h>
#include <math.h>

void init_light(Light* light) {
    light->intensity = 1.0f;
    light->current_intensity = 1.0f;
    light->time = 0.0f;
}

void update_light(Light* light, const App* app) {
    if (app->key_plus) {
        light->intensity += 0.005f;
    }

    if (app->key_minus) {
        light->intensity -= 0.005f;
    }

    if (light->intensity < 0.05f) {
        light->intensity = 0.05f;
    }

    if (light->intensity > 3.0f) {
        light->intensity = 3.0f;
    }

    light->time += 0.05f;

    float flicker = 0.4f * sinf(light->time * 3.5f);

    light->current_intensity = light->intensity + flicker;
}

void apply_light(const Light* light, const Camera* camera) {
    GLfloat position[] = {
        camera->x,
        camera->y,
        camera->z,
        1.0f
    };

    GLfloat diffuse[] = {
        1.0f * light->intensity,
        0.65f * light->intensity,
        0.35f * light->intensity,
        1.0f
    };

    GLfloat ambient[] = {
        0.08f,
        0.06f,
        0.04f,
        1.0f
    };

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
}