#include "app.h"

#include <stdio.h>

int init_app(App* app)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL error: %s\n", SDL_GetError());
        return 0;
    }

    app->window = SDL_CreateWindow(
        "Haunted Room",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    if (!app->window) {
        fprintf(stderr, "Window error: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    app->context = SDL_GL_CreateContext(app->window);

    if (!app->context) {
        fprintf(stderr, "OpenGL error: %s\n", SDL_GetError());
        SDL_DestroyWindow(app->window);
        SDL_Quit();
        return 0;
    }

    app->is_running = true;

    return 1;
}

void handle_app_events(App* app)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            app->is_running = false;
        }

        if (event.type == SDL_KEYDOWN &&
            event.key.keysym.sym == SDLK_ESCAPE) {
            app->is_running = false;
        }
    }
}

void destroy_app(App* app)
{
    SDL_GL_DeleteContext(app->context);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
}