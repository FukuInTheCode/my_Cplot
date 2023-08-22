#include "../../includes/my.h"

static void my_plot_point(my_fig_t *fig)
{
    my_fig_calc_scale(fig);
    for (size_t i = 0; i < fig->plot->num; i++) {
        sfCircleShape *current_point = sfCircleShape_create();
        sfCircleShape_setRadius(current_point, fig->ui->point_radius);
        sfVector2f pos = {
            .x = fig->plot->xs[i] * fig->plot->ratio.x +\
                    fig->plot->margin_left,
            .y = sfRenderWindow_getSize(fig->window).y - \
                    fig->plot->ys[i] * fig->plot->ratio.y -\
                    fig->ui->point_radius * 2 - fig->plot->margin_up
        };

        sfCircleShape_setFillColor(current_point, fig->plot->xs[i] != 0 ? fig->ui->point : sfBlue);

        sfCircleShape_setPosition(current_point, pos);
        sfRenderWindow_drawCircleShape(fig->window, current_point, NULL);
        sfCircleShape_destroy(current_point);
    }
}

static void my_plot_axes(my_fig_t *fig)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    sfVertex line[] = {
        {{0, fig->plot->axe2}, sfWhite},
        {{tmp_vec.x, fig->plot->axe2}, sfWhite}
    };

    sfRenderWindow_drawPrimitives(fig->window, line, 2, sfLines, NULL);
    sfVertex line2[] = {
        {{fig->plot->axe1, 0}, sfWhite},
        {{fig->plot->axe1, tmp_vec.y}, sfWhite}
    };

    sfRenderWindow_drawPrimitives(fig->window, line2, 2, sfLines, NULL);
}

void my_fig_show(my_fig_t *fig)
{
    while (sfRenderWindow_isOpen(fig->window)) {
        while (sfRenderWindow_pollEvent(fig->window, fig->event)) {
            if (fig->event->type == sfEvtClosed){
                sfRenderWindow_close(fig->window);
            }
        }
        sfRenderWindow_clear(fig->window, fig->ui->background);
        my_plot_point(fig);
        my_plot_axes(fig);
        sfRenderWindow_display(fig->window);
    }
    sfRenderWindow_destroy(fig->window);
}
