#include "scene.h"
#include "app.h"

#include <GL/gl.h>
#include <GL/glu.h>

static void draw_room(void)
{
    glBegin(GL_QUADS);

    // padló
    glColor3f(0.13f, 0.13f, 0.13f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f( 5.0f, -5.0f, 0.0f);
    glVertex3f( 5.0f,  5.0f, 0.0f);
    glVertex3f(-5.0f,  5.0f, 0.0f);

    // plafon
    glColor3f(0.18f, 0.16f, 0.15f);
    glVertex3f(-5.0f, -5.0f, 3.0f);
    glVertex3f(-5.0f,  5.0f, 3.0f);
    glVertex3f( 5.0f,  5.0f, 3.0f);
    glVertex3f( 5.0f, -5.0f, 3.0f);

    // hátsó fal
    glColor3f(0.32f, 0.30f, 0.28f);
    glVertex3f(-5.0f, 5.0f, 0.0f);
    glVertex3f( 5.0f, 5.0f, 0.0f);
    glVertex3f( 5.0f, 5.0f, 3.0f);
    glVertex3f(-5.0f, 5.0f, 3.0f);

    // első fal
    glColor3f(0.30f, 0.28f, 0.26f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f(-5.0f, -5.0f, 3.0f);
    glVertex3f( 5.0f, -5.0f, 3.0f);
    glVertex3f( 5.0f, -5.0f, 0.0f);

    // bal fal
    glColor3f(0.28f, 0.26f, 0.24f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f(-5.0f,  5.0f, 0.0f);
    glVertex3f(-5.0f,  5.0f, 3.0f);
    glVertex3f(-5.0f, -5.0f, 3.0f);

    // jobb fal
    glColor3f(0.28f, 0.26f, 0.24f);
    glVertex3f(5.0f, -5.0f, 0.0f);
    glVertex3f(5.0f, -5.0f, 3.0f);
    glVertex3f(5.0f,  5.0f, 3.0f);
    glVertex3f(5.0f,  5.0f, 0.0f);

    glEnd();
}

void init_scene(void)
{
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearColor(0.02f, 0.02f, 0.025f, 1.0f);
}

void render_scene(const Camera* camera)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    apply_camera(camera);

    draw_room();
}