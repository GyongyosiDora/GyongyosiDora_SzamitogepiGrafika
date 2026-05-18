#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

typedef struct App {
    SDL_Window* window;
    SDL_GLContext context;
    bool is_running;

    bool key_w;
    bool key_a;
    bool key_s;
    bool key_d;

    float mouse_dx;
    float mouse_dy;

    bool key_plus;
    bool key_minus;
} App;

int init_app(App* app);
void handle_app_events(App* app);
void destroy_app(App* app);

#endif