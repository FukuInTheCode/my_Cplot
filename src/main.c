#include "../includes/my.h"

int main(void)
{


    my_plot_t plt = {.title = "Test"};
    plt.mode.height = 1000;
    plt.mode.width = 1000;
    plt.mode.bitsPerPixel = 32;
    plt.window = sfRenderWindow_create(plt.mode, plt.title, sfDefaultStyle, NULL);

    uint32_t n = 4;

    double xs[] = { 1, 2, 3, 4 };
    double ys[] = { 1, 2, 3, 4 };

    sfVector2u window_size = sfRenderWindow_getSize(plt.window);

    sfVector2f ratio = {
        window_size.x / (my_max(xs, n) - my_min(xs, n)),
        window_size.y / (my_max(ys, n) - my_min(ys, n))
    };


    while (sfRenderWindow_isOpen(plt.window)) {

        while (sfRenderWindow_pollEvent(plt.window, &(plt.event))) {
            if (plt.event.type == sfEvtClosed) {
                sfRenderWindow_close(plt.window);
            }
        }

        sfRenderWindow_clear(plt.window, sfWhite);
        for (uint32_t i = 0; i < n; ++i) {
            sfCircleShape *pts = sfCircleShape_create();
            sfVector2f pos = {
                xs[i] * ratio.x,
                ys[i] * ratio.y
            };
            sfCircleShape_setPosition(pts, pos);
            sfCircleShape_setRadius(pts, 10);
            sfCircleShape_setFillColor(pts, sfBlack);
            sfRenderWindow_drawCircleShape(plt.window, pts, NULL);
            sfCircleShape_destroy(pts);
        }

    }

    sfRenderWindow_destroy(plt.window);
    return 0;
}
