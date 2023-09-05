#include "../../includes/my.h"

void my_plot_axis(my_plot_t *plt)
{
    sfVertex axe_y[] = {
        {{0, window_size.y / 2 + plt->shift.y}, plt->th->axis, {0, 0}},
        {{window_size.x, window_size.y / 2 + plt->shift.y}, plt->th->axis, {0, 0}}
    };
    sfVertex axe_x[] = {
        {{window_size.x / 2 + plt->shift.x, 0}, plt->th->axis, {0, 0}},
        {{window_size.x / 2 + plt->shift.x, window_size.y}, plt->th->axis, {0, 0}}
    };
    if (axe_x[0].position.x > 0 && axe_x[0].position.x < window_size.x)
        sfRenderWindow_drawPrimitives(plt->window, axe_x, 2, sfLines, NULL);
    if (axe_y[0].position.y > 0 && axe_y[0].position.y < window_size.y)
        sfRenderWindow_drawPrimitives(plt->window, axe_y, 2, sfLines, NULL);
}
