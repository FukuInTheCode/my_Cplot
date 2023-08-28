#include "../../includes/my.h"

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt)
{
    plt->window = sfRenderWindow_create(*md, title, sfDefaultStyle, NULL);
    plt->event = evt;

    plt->is_dragged = sfFalse;
    plt->shift.x = 0;
    plt->shift.y = 0;
    plt->last_shift.x = 0;
    plt->last_shift.y = 0;

    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    plt->ratio.x = tmp_vec.x;
    plt->ratio.y = tmp_vec.y;

    for (uint32_t i = 0; i < plt->graph_n; ++i) {
        calc_ratio(plt, plt->graph[i], 2);
        compute_pts(plt, plt->graph[i]);
    }

}
