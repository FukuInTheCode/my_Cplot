#include "../../includes/my.h"

void my_plot_axis(my_plot_t *plt)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    sfVertex line[] = {
        {{0, plt->graph->shift.y + tmp_vec.y / 2}, plt->theme->axis},
        {{tmp_vec.x, plt->graph->shift.y + tmp_vec.y / 2}, plt->theme->axis}
    };
    if (my_plot_is_onscreen(plt, line[0].position, axis))
        sfRenderWindow_drawPrimitives(plt->window, line, 2, sfLines, NULL);
    
    sfVertex line2[] = {
        {{tmp_vec.x / 2 + plt->graph->shift.x, 0}, plt->theme->axis},
        {{tmp_vec.x / 2 + plt->graph->shift.x, tmp_vec.y}, plt->theme->axis}
    };
    if (my_plot_is_onscreen(plt, line2[0].position, axis))
        sfRenderWindow_drawPrimitives(plt->window, line2, 2, sfLines, NULL);
}
