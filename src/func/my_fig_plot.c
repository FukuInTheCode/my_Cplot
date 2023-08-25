#include "../../includes/my.h"

void my_plot(my_fig_t *fig)
{
        sfRenderWindow_clear(fig->window, fig->ui->background);
        my_plot_handle_mouse(fig);

        if (fig->plot->type == function_pts)
            my_plot_function(fig);

        my_fig_calc_scale(fig);
        my_plot_point(fig);
        my_plot_axes(fig);
        sfRenderWindow_display(fig->window);
}