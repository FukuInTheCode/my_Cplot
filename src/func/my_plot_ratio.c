#include "../../includes/my.h"

void calc_ratio(my_plot_t *plt)
{
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);
    double max_x = my_max(plt->gs[0]->xs, plt->gs[0]->pts_n);
    double min_x = my_min(plt->gs[0]->xs, plt->gs[0]->pts_n);
    double max_y = my_max(plt->gs[0]->ys, plt->gs[0]->pts_n);
    double min_y = my_min(plt->gs[0]->ys, plt->gs[0]->pts_n);
    double max_radius = plt->gs[0]->th->radius;
    for (uint32_t i = 1; i < plt->gs_n; ++i) {
        max_x = my_max_between(max_x,  my_max(plt->gs[i]->xs,\
                                                plt->gs[i]->pts_n));
        min_x = my_min_between(min_x,  my_min(plt->gs[i]->xs,\
                                                plt->gs[i]->pts_n));
        max_y = my_max_between(max_y,  my_max(plt->gs[i]->ys,\
                                                plt->gs[i]->pts_n));
        min_y = my_min_between(min_y,  my_min(plt->gs[i]->ys,\
                                                plt->gs[i]->pts_n));
        max_radius = my_max_between(max_radius, plt->gs[i]->th->radius);
    }
    plt->ratio.x = (window_size.x - max_radius) / (max_x - min_x + 0.1) / 2;
    plt->ratio.y = (window_size.y - max_radius) / (max_y - min_y + 0.1) / 2;
}
