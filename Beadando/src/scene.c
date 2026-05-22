#include "scene.h"
#include "app.h"
#include "light.h"
#include "draw.h"
#include <GL/gl.h>
#include <stdio.h>

static void set_perspective(void) {
    double aspect = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;

    double near_plane = 0.1;
    double far_plane = 100.0;
    double top = 0.07;
    double bottom = -top;
    double right = top * aspect;
    double left = -right;

    glFrustum(left, right, bottom, top, near_plane, far_plane);
}

int init_scene(Scene* scene) {
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    set_perspective();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0.02f, 0.02f, 0.025f, 1.0f);

    if (!load_model(&scene->torch, "assets/models/torch.obj")) {
        fprintf(stderr, "Failed to load torch model.\n");
        return 0;
    }

    return 1;
}

void render_scene(const Scene* scene, const Camera* camera, const Light* light) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // fény a kamera előtt, a fáklya helyéhez igazítva
    GLfloat light_pos[] = {1.1f, -0.45f, -1.2f, 1.0f};

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

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

    apply_camera(camera);

    draw_room();
    draw_test_box();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glTranslatef(1.1f, -0.45f, -1.2f);
    glRotatef(270.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(-20.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.5f, 0.5f, 0.5f);

    glColor3f(0.3f, 0.15f, 0.07f);
    draw_model(&scene->torch);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void destroy_scene(Scene* scene) {
    destroy_model(&scene->torch);
}