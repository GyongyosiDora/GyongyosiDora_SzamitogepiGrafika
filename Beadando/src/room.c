#include "room.h"
#include <GL/gl.h>

void draw_room(void) {
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
void draw_test_box(void) {
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