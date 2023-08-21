#include "../../includes/my.h"

void my_fig_plot(my_fig_t *fig)
{
    for (size_t i = 0; i < fig->plot->num; i++) {
        sfCircleShape *current_point = sfCircleShape_create();
        sfCircleShape_setRadius(current_point, 10);
        sfVector2f pos = {
            .x = fig->plot->xs[i],
            .y = sfRenderWindow_getSize(fig->window).y - fig->plot->ys[i] - 20 - my_abs(fig->plot->min_y),
        };

    sfCircleShape_setPosition(current_point, pos);
    sfRenderWindow_drawCircleShape(fig->window, current_point, NULL);
    sfCircleShape_destroy(current_point);
    }
}