#include "../../includes/my.h"

static void my_plot(my_fig_t *fig)
{
    my_plot_calc_scale(fig);
    for (size_t i = 0; i < fig->plot->num; i++) {
        sfCircleShape *current_point = sfCircleShape_create();
        sfCircleShape_setRadius(current_point, 10);
        sfVector2f pos = {
            .x = fig->plot->xs[i] * fig->plot->ratio.x + fig->plot->min_x,
            .y =  sfRenderWindow_getSize(fig->window).y - \
                    fig->plot->ys[i] * fig->plot->ratio.y - 20 -\
                    fig->plot->min_y
        };

    sfCircleShape_setPosition(current_point, pos);
    sfRenderWindow_drawCircleShape(fig->window, current_point, NULL);
    sfCircleShape_destroy(current_point);
    }
}

void my_fig_show(my_fig_t *fig)
{
    while (sfRenderWindow_isOpen(fig->window)) {
        while (sfRenderWindow_pollEvent(fig->window, fig->event)) {
            if (fig->event->type == sfEvtClosed){
                sfRenderWindow_close(fig->window);
            }
        }
        sfRenderWindow_clear(fig->window, fig->colors->background);
        my_plot(fig);
        sfRenderWindow_display(fig->window);
    }
    sfRenderWindow_destroy(fig->window);
}
