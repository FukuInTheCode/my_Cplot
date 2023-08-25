#include "../../includes/my.h"

void my_plot(my_fig_t *fig)
{
        sfRenderWindow_clear(fig->window, fig->ui->background);
        my_plot_handle_mouse(fig);
        my_plot_point(fig);
        my_plot_axes(fig);
        sfRenderWindow_display(fig->window);
}