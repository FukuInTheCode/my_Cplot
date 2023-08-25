#include "../../includes/my.h"

void my_fig_show(my_fig_t *fig)
{
    while (sfRenderWindow_isOpen(fig->window)) {
        while (sfRenderWindow_pollEvent(fig->window, fig->event)) {
            my_fig_handle_event(fig);
        }
        sfRenderWindow_clear(fig->window, fig->ui->background);
        my_plot_handle_mouse(fig);
        my_plot_point(fig);
        my_plot_axes(fig);
        sfRenderWindow_display(fig->window);
    }
    sfRenderWindow_destroy(fig->window);
}
