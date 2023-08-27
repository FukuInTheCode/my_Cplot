#include "../../includes/my.h"

static inline __attribute__((always_inline)) void mouse_handler(my_plot_t *plt)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i mouse_vec = sfMouse_getPosition(plt->window);
        if (!plt->is_dragged) {
            plt->is_dragged = sfTrue;
            plt->last_shift = mouse_vec;
        } else {
            plt->shift.x += mouse_vec.x - plt->last_shift.x;
            plt->shift.y += mouse_vec.y - plt->last_shift.y;
            plt->last_shift = mouse_vec;
        }
    } else
        plt->is_dragged = sfFalse;
}

void my_plot_show(my_plot_t *plt)
{
    while (sfRenderWindow_isOpen(plt->window)) {
        my_plot_handle_event(plt);
        mouse_handler(plt);

        sfRenderWindow_clear(plt->window, plt->theme->plot.bg);
        my_plot_axis(plt);
        for (uint32_t i = 0; i < plt->graph_n; ++i) {
            if (plt->graph[i]->type == func)
                my_plot_func(plt, plt->graph[i]);
            my_plot_points(plt, plt->graph[i]);
        }
        sfRenderWindow_display(plt->window);
    }
}
