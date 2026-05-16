#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <stdbool.h>
#include <stdio.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

static void init_opengl(void)
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

static void draw_cube(void)
{
    glBegin(GL_QUADS);

    glColor3f(0.6f, 0.2f, 0.2f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);

    glColor3f(0.2f, 0.6f, 0.2f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3f(0.2f, 0.2f, 0.6f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    glColor3f(0.6f, 0.6f, 0.2f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glColor3f(0.6f, 0.2f, 0.6f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);

    glColor3f(0.2f, 0.6f, 0.6f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);

    glEnd();
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Haunted Room",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        fprintf(stderr, "Window error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);

    if (!context) {
        fprintf(stderr, "OpenGL error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    init_opengl();

    bool running = true;

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYDOWN &&
                event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.0f, 0.0f, -6.0f);
        glRotatef(25.0f, 1.0f, 0.0f, 0.0f);
        glRotatef(35.0f, 0.0f, 1.0f, 0.0f);

        draw_cube();

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}