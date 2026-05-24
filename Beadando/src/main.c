#include "app.h"
#include "scene.h"
#include "camera.h"
#include "light.h"

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    App app;
    Camera camera;
    Light light;
    Scene scene;

    if (!init_app(&app)) {
        return 1;
    }

    init_camera(&camera);
    init_light(&light);
    
    if (!init_scene(&scene)) {
        destroy_app(&app);
        return 1;
    }

    while (app.is_running) {
        handle_app_events(&app);
        rotate_camera(&camera, app.mouse_dx, app.mouse_dy);
        update_camera(&camera, &app);
        update_light(&light, &app);
        update_scene(&scene, &app);
        render_scene(&scene, &camera, &light);
        SDL_GL_SwapWindow(app.window);
    }

    destroy_scene(&scene);
    destroy_app(&app);

    return 0;
}