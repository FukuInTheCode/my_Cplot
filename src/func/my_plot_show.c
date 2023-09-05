#include "../../includes/my.h"

static handling_shit(my_plot_t *plt)
{
    my_plot_handle_mouse(plt);
    my_plot_handle_zoom(plt);
    my_plot_handle_shift(plt);
}

void my_plot_show(my_plot_t *plt)
{
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);
    while (sfRenderWindow_isOpen(plt->window)) {

        my_plot_handle_events(plt);

        sfRenderWindow_clear(plt->window, plt->th->bg);

        my_plot_axis(plt);

        // pts plotting
        for (uint32_t j = 0; j < plt->gs_n; ++j)
            my_plot_pts(plt , plt->gs[j]);

        // end plotting
        sfRenderWindow_display(plt->window);

    }
}
