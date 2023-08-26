#include "../../includes/my.h"

static inline __attribute__((always_inline)) void mouse_handler(my_plot_t *plt)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfVector2i mouse_vec = sfMouse_getPosition(plt->window);
        if (!plt->graph->is_dragged) {
            plt->graph->is_dragged = sfTrue;
            plt->graph->last_shift = mouse_vec;
        }
        else {
            plt->graph->shift.x += mouse_vec.x - plt->graph->last_shift.x;
            plt->graph->shift.y += mouse_vec.y - plt->graph->last_shift.y;
            plt->graph->last_shift = mouse_vec;
        }
    } else
        plt->graph->is_dragged = sfFalse;
}

void my_plot_show(my_plot_t *plt)
{
    while (sfRenderWindow_isOpen(plt->window)) {
        my_plot_handle_event(plt);
        mouse_handler(plt);

        sfRenderWindow_clear(plt->window, plt->theme->bg);
        my_plot_axis(plt);
        if (plt->graph->type == static_func)
            my_plot_func(plt);
        my_plot_points(plt);
        sfRenderWindow_display(plt->window);
    }
}
