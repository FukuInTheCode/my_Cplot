#include "../../includes/my.h"

static void handling_shit(my_plot_t *plt)
{
    my_plot_handle_mouse(plt);
    my_plot_handle_zoom(plt);
    my_plot_handle_shift(plt);
}

static void plot_graphs(my_plot_t *plt)
{
    for (uint32_t j = 0; j < plt->gs_n; ++j) {
        my_plot_pts(plt , plt->gs[j]);
    }
}

void my_plot_show(my_plot_t *plt)
{
    while (sfRenderWindow_isOpen(plt->window)) {

        my_plot_handle_events(plt);

        sfRenderWindow_clear(plt->window, plt->th->bg);

        handling_shit(plt);

        my_plot_axis(plt);

        plot_graphs(plt);

        sfRenderWindow_display(plt->window);

    }
}
