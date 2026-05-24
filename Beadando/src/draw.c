#include "draw.h"
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

// fáklya
void draw_torch(const Model* model) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glTranslatef(1.1f, -0.45f, -1.2f);
    glRotatef(0.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(-10.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.5f, 0.5f, 0.5f);

    glColor3f(0.3f, 0.15f, 0.07f);
    draw_model(model);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

// asztal
void draw_table(void)
{
    glColor3f(0.35f, 0.18f, 0.08f);

    // asztallap
    glPushMatrix();
    glTranslatef(2.0f, 2.0f, 0.9f);

    glBegin(GL_QUADS);

    // teteje
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.8f, -0.6f,  0.05f);
    glVertex3f( 0.8f, -0.6f,  0.05f);
    glVertex3f( 0.8f,  0.6f,  0.05f);
    glVertex3f(-0.8f,  0.6f,  0.05f);

    // alja
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-0.8f, -0.6f, 0.0f);
    glVertex3f(-0.8f,  0.6f, 0.0f);
    glVertex3f( 0.8f,  0.6f, 0.0f);
    glVertex3f( 0.8f, -0.6f, 0.0f);

    // eleje
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(-0.8f, -0.6f, 0.0f);
    glVertex3f( 0.8f, -0.6f, 0.0f);
    glVertex3f( 0.8f, -0.6f, 0.05f);
    glVertex3f(-0.8f, -0.6f, 0.05f);

    // hátulja
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.8f,  0.6f, 0.0f);
    glVertex3f(-0.8f,  0.6f, 0.05f);
    glVertex3f( 0.8f,  0.6f, 0.05f);
    glVertex3f( 0.8f,  0.6f, 0.0f);

    // bal
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.8f, -0.6f, 0.0f);
    glVertex3f(-0.8f, -0.6f, 0.05f);
    glVertex3f(-0.8f,  0.6f, 0.05f);
    glVertex3f(-0.8f,  0.6f, 0.0f);

    // jobb
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.8f, -0.6f, 0.0f);
    glVertex3f( 0.8f,  0.6f, 0.0f);
    glVertex3f( 0.8f,  0.6f, 0.05f);
    glVertex3f( 0.8f, -0.6f, 0.05f);

    glEnd();

    // lábak
    float leg_x[4] = { -0.65f,  0.65f, -0.65f,  0.65f };
    float leg_y[4] = { -0.45f, -0.45f,  0.45f,  0.45f };

    int i;
    for (i = 0; i < 4; i++) {
        glBegin(GL_QUADS);

        // eleje
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] - 0.06f,  0.0f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] - 0.06f,  0.0f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] - 0.06f, -0.9f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] - 0.06f, -0.9f);

        // hátulja
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] + 0.06f,  0.0f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] + 0.06f, -0.9f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] + 0.06f, -0.9f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] + 0.06f,  0.0f);

        // bal
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] - 0.06f,  0.0f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] - 0.06f, -0.9f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] + 0.06f, -0.9f);
        glVertex3f(leg_x[i] - 0.06f, leg_y[i] + 0.06f,  0.0f);

        // jobb
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] - 0.06f,  0.0f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] + 0.06f,  0.0f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] + 0.06f, -0.9f);
        glVertex3f(leg_x[i] + 0.06f, leg_y[i] - 0.06f, -0.9f);

        glEnd();
    }

    glPopMatrix();
}

// láda
void draw_chest(const Model* body, const Model* lid, float lid_angle)
{
    glPushMatrix();

    glTranslatef(2.0f, 2.0f, 0.95f);
    glScalef(0.25f, 0.25f, 0.25f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);  // OBJ Y-fel → GL Z-fel

    glColor3f(0.45f, 0.25f, 0.12f);
    draw_model(body);

    // fedél forgatása a zsanér körül (OBJ Y=1.738 → GL Z=1.738)
    glTranslatef(0.0f, 1.738f, -1.236f);
    glRotatef(-lid_angle, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, -1.738f, 1.236f);

    glColor3f(0.38f, 0.20f, 0.09f);
    draw_model(lid);

    glPopMatrix();
}