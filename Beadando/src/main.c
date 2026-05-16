#include "app.h"
#include "scene.h"
#include "camera.h"

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    App app;
    Camera camera;

    if (!init_app(&app)) {
        return 1;
    }

    init_camera(&camera);
    init_scene();

    while (app.is_running) {
        handle_app_events(&app);
        update_camera(&camera, &app);
        render_scene(&camera);
        SDL_GL_SwapWindow(app.window);
    }

    destroy_app(&app);

    return 0;
}