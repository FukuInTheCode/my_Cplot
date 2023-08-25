#include "../../includes/my.h"

static void my_plot_point(my_fig_t *fig)
{
    my_fig_calc_scale(fig);
    for (size_t i = 0; i < fig->plot->num; i++) {
        sfCircleShape *current_point = sfCircleShape_create();
        sfCircleShape_setRadius(current_point, fig->ui->point_radius);
        sfVector2f pos = {
            .x = fig->plot->xs[i] * fig->plot->ratio.x +\
                    fig->plot->hor_shift,
            .y = sfRenderWindow_getSize(fig->window).y - \
                    fig->plot->ys[i] * fig->plot->ratio.y -\
                    fig->ui->point_radius * 3 - fig->plot->ver_shift
        };
        if (fig->plot->axe2 == 40 + fig->ui->point_radius) pos.x += 40;
        if (fig->plot->axe1 == sfRenderWindow_getSize(fig->window).y - 40)
            pos.y -= 40 - fig->ui->point_radius * 2;
        sfCircleShape_setFillColor(current_point, fig->plot->ys[i] != 0 ? \
                                    fig->ui->point : sfBlue);
        sfCircleShape_setPosition(current_point, pos);
        sfRenderWindow_drawCircleShape(fig->window, current_point, NULL);
        sfCircleShape_destroy(current_point);
    }
}

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
