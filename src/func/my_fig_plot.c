#include "../../includes/my.h"

void my_plot(my_fig_t *fig)
{
        sfRenderWindow_clear(fig->window, fig->ui->background);
        my_plot_handle_mouse(fig);
        my_fig_calc_scale(fig);
        if (fig->plot->type == points)
            my_plot_point(fig);
        else if (fig->plot->type == function_pts)
            printf("TODO\n");
        my_plot_axes(fig);
        sfRenderWindow_display(fig->window);
}