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

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // köd beállítás
    GLfloat fog_color[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogfv(GL_FOG_COLOR, fog_color);
    glFogf(GL_FOG_DENSITY, 0.4f);

    if (!load_model(&scene->torch, "assets/models/torch.obj")) {
        fprintf(stderr, "Failed to load torch model.\n");
        return 0;
    }

    scene->chest.is_open   = false;
    scene->chest.lid_angle = 0.0f;

    if (!load_model_named(&scene->chest.body, "assets/models/chest.obj", "Chest_base")) {
       fprintf(stderr, "Failed to load chest base.\n");
       return 0;
    }

    if (!load_model_named(&scene->chest.lid, "assets/models/chest.obj", "Chest_lid")) {
       fprintf(stderr, "Failed to load chest lid.\n");
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
        1.0f * light->current_intensity,
        0.65f * light->current_intensity,
        0.35f * light->current_intensity,
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
    //draw_test_box();
    draw_table();
    draw_chest(&scene->chest.body, &scene->chest.lid, scene->chest.lid_angle);
    draw_torch(&scene->torch);
}

void destroy_scene(Scene* scene) {
    destroy_model(&scene->torch);
    destroy_model(&scene->chest.body);
    destroy_model(&scene->chest.lid);
}

void update_scene(Scene* scene, const App* app) {
    if (app->key_e && !app->key_e_prev) {
        scene->chest.is_open = !scene->chest.is_open;
    }

    if (scene->chest.is_open && scene->chest.lid_angle < 90.0f) {
        scene->chest.lid_angle += 2.0f;
        if (scene->chest.lid_angle > 90.0f) {
            scene->chest.lid_angle = 90.0f;
        }
    }

    if (!scene->chest.is_open && scene->chest.lid_angle > 0.0f) {
        scene->chest.lid_angle -= 2.0f;
        if (scene->chest.lid_angle < 0.0f) {
            scene->chest.lid_angle = 0.0f;
        }
    }
}