#include "../../includes/my.h"

void my_plot_show(my_plot_t *plt)
{
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);
    while (sfRenderWindow_isOpen(plt->window)) {

        my_plot_handle_events(plt);

        sfRenderWindow_clear(plt->window, plt->th->bg);

        my_plot_handle_mouse(plt);

        my_plot_handle_zoom(plt);

        my_plot_handle_shift(plt);

        // pts plotting
        for (uint32_t j = 0; j < plt->gs_n; ++j) {
            for (uint32_t i = 0; i < plt->gs[j]->pts_n; ++i) {
                sfCircleShape *pts = sfCircleShape_create();
                sfVector2f pos = {
                    plt->gs[j]->xs[i] * (plt->ratio.x + plt->zoom.x) + window_size.x / 2 - 10 + plt->shift.x,
                    window_size.y - plt->gs[j]->ys[i] * (plt->ratio.y + plt->zoom.y) - 10 - window_size.y / 2 + plt->shift.y
                };
                if (pos.x <= -20 || pos.x >= window_size.x || pos.y <= -20 || pos.y >= window_size.y)
                    continue;
                sfCircleShape_setPosition(pts, pos);
                sfCircleShape_setRadius(pts, plt->gs[j]->th->radius);
                sfCircleShape_setFillColor(pts, plt->gs[j]->th->point);
                sfRenderWindow_drawCircleShape(plt->window, pts, NULL);
                sfCircleShape_destroy(pts);
            }
        }

        // end plotting
        sfRenderWindow_display(plt->window);

    }
}
