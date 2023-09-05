#include "../../includes/my.h"

static void calc_ratio(my_plot_t *plt)
{
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);
    double max_x = my_max(plt->gs[0]->xs, plt->gs[0]->pts_n);
    double min_x = my_min(plt->gs[0]->xs, plt->gs[0]->pts_n);
    double max_y = my_max(plt->gs[0]->ys, plt->gs[0]->pts_n);
    double min_y = my_min(plt->gs[0]->ys, plt->gs[0]->pts_n);
    for (uint32_t i = 1; i < plt->gs_n; ++i) {
        max_x = my_max_between(max_x,  my_max(plt->gs[i]->xs, plt->gs[i]->pts_n));
        min_x = my_min_between(min_x,  my_min(plt->gs[i]->xs, plt->gs[i]->pts_n));
        max_y = my_max_between(max_x,  my_max(plt->gs[i]->ys, plt->gs[i]->pts_n));
        min_y = my_min_between(max_x,  my_min(plt->gs[i]->ys, plt->gs[i]->pts_n));
    }
    plt->ratio.x = (window_size.x - 10) / (max_x - min_x + 0.1) / 2;
    plt->ratio.y = (window_size.y - 10) / (max_y - min_y + 0.1) / 2;
}

void my_plot_create(my_plot_t *plt, my_theme_t *th)
{
    sfVideoMode mode = {1000, 1000, 32};
    plt->window = sfRenderWindow_create(mode, plt->title, sfDefaultStyle, NULL);
    plt->shift.x = 0;
    plt->shift.y = 0;
    plt->mouse_save.x = 0;
    plt->mouse_save.y = 0;
    plt->zoom.x = 0;
    plt->zoom.y = 0;
    plt->th = th;
    calc_ratio(plt);
}
