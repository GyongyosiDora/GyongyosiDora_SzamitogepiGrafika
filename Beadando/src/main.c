#include "app.h"
#include "scene.h"

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    App app;

    if (!init_app(&app)) {
        return 1;
    }

    init_scene();

    while (app.is_running) {
        handle_app_events(&app);
        render_scene();
        SDL_GL_SwapWindow(app.window);
    }

    destroy_app(&app);

    return 0;
}