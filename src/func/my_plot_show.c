#include "../../includes/my.h"

void my_plot_show(my_plot_t *plt)
{
    while (sfRenderWindow_isOpen(plt.window)) {

        my_plot_handle_event(plt);

        my_plot_handle_mouse(plt);

        sfRenderWindow_clear(plt->window, plt->theme->bg);

        my_plot_axis(plt);

        my_plot_points(plt);

        sfRenderWindow_display(plt.window);
    }
}