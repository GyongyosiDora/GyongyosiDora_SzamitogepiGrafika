#include "scene.h"
#include "app.h"

#include <GL/gl.h>
#include <GL/glu.h>

static void draw_room(void)
{
    glBegin(GL_QUADS);

    // padló: felfelé néz
    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor3f(0.13f, 0.13f, 0.13f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f( 5.0f, -5.0f, 0.0f);
    glVertex3f( 5.0f,  5.0f, 0.0f);
    glVertex3f(-5.0f,  5.0f, 0.0f);

    // plafon: lefelé néz
    glNormal3f(0.0f, 0.0f, -1.0f);
    glColor3f(0.18f, 0.16f, 0.15f);
    glVertex3f(-5.0f, -5.0f, 3.0f);
    glVertex3f(-5.0f,  5.0f, 3.0f);
    glVertex3f( 5.0f,  5.0f, 3.0f);
    glVertex3f( 5.0f, -5.0f, 3.0f);

    // hátsó fal: befelé, negatív y irányba
    glNormal3f(0.0f, -1.0f, 0.0f);
    glColor3f(0.32f, 0.30f, 0.28f);
    glVertex3f(-5.0f, 5.0f, 0.0f);
    glVertex3f( 5.0f, 5.0f, 0.0f);
    glVertex3f( 5.0f, 5.0f, 3.0f);
    glVertex3f(-5.0f, 5.0f, 3.0f);

    // első fal: befelé, pozitív y irányba
    glNormal3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.30f, 0.28f, 0.26f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f(-5.0f, -5.0f, 3.0f);
    glVertex3f( 5.0f, -5.0f, 3.0f);
    glVertex3f( 5.0f, -5.0f, 0.0f);

    // bal fal: befelé, pozitív x irányba
    glNormal3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.28f, 0.26f, 0.24f);
    glVertex3f(-5.0f, -5.0f, 0.0f);
    glVertex3f(-5.0f,  5.0f, 0.0f);
    glVertex3f(-5.0f,  5.0f, 3.0f);
    glVertex3f(-5.0f, -5.0f, 3.0f);

    // jobb fal: befelé, negatív x irányba
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glColor3f(0.28f, 0.26f, 0.24f);
    glVertex3f(5.0f, -5.0f, 0.0f);
    glVertex3f(5.0f, -5.0f, 3.0f);
    glVertex3f(5.0f,  5.0f, 3.0f);
    glVertex3f(5.0f,  5.0f, 0.0f);

    glEnd();
}

// fény teszteléshez
static void draw_test_box(void)
{
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.6f);
    glScalef(1.2f, 0.8f, 0.6f);

    glBegin(GL_QUADS);

    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor3f(0.45f, 0.25f, 0.12f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    glEnd();

    glPopMatrix();
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
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0.02f, 0.02f, 0.025f, 1.0f);
}

void render_scene(const Camera* camera, const Light* light)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    apply_camera(camera);
    apply_light(light, camera);

    draw_room();
    draw_test_box();
}