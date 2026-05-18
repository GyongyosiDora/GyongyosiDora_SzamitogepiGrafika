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

    app->key_w = false;
    app->key_a = false;
    app->key_s = false;
    app->key_d = false;

    app->mouse_dx = 0.0f;
    app->mouse_dy = 0.0f;

    app->key_plus = false;
    app->key_minus = false;

    SDL_SetRelativeMouseMode(SDL_TRUE);

    return 1;
}

void handle_app_events(App* app)
{
    SDL_Event event;

    app->mouse_dx = 0.0f;
    app->mouse_dy = 0.0f;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            app->is_running = false;
        }

        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                app->is_running = false;
            }

            if (event.key.keysym.sym == SDLK_w) {
                app->key_w = true;
            }

            if (event.key.keysym.sym == SDLK_a) {
                app->key_a = true;
            }

            if (event.key.keysym.sym == SDLK_s) {
                app->key_s = true;
            }

            if (event.key.keysym.sym == SDLK_d) {
                app->key_d = true;
            }

            if (event.key.keysym.sym == SDLK_PLUS || event.key.keysym.sym == SDLK_KP_PLUS) {
                app->key_plus = true;
            }

            if (event.key.keysym.sym == SDLK_MINUS || event.key.keysym.sym == SDLK_KP_MINUS) {
                app->key_minus = true;
            }
        }

        if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_w) {
                app->key_w = false;
            }

            if (event.key.keysym.sym == SDLK_a) {
                app->key_a = false;
            }

            if (event.key.keysym.sym == SDLK_s) {
                app->key_s = false;
            }

            if (event.key.keysym.sym == SDLK_d) {
                app->key_d = false;
            }

            if (event.key.keysym.sym == SDLK_PLUS || event.key.keysym.sym == SDLK_KP_PLUS) {
                app->key_plus = false;
            }

            if (event.key.keysym.sym == SDLK_MINUS || event.key.keysym.sym == SDLK_KP_MINUS) {
                app->key_minus = false;
            }
        }

        if (event.type == SDL_MOUSEMOTION) {
            app->mouse_dx += (float)event.motion.xrel;
            app->mouse_dy += (float)event.motion.yrel;
        }
    }
}

void destroy_app(App* app)
{
    SDL_GL_DeleteContext(app->context);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
}