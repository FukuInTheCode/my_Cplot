#include "../../includes/my.h"

static inline __attribute__((always_inline)) void find_extrema(my_plot_t *plt)
{
    plt->graph->max_values.x = 0;
    plt->graph->max_values.y = 0;
    plt->graph->min_values.x = 0;
    plt->graph->min_values.y = 0;
    for (size_t i = 0; i < plt->graph->data_num; ++i) {
        if (plt->graph->points[i].x > plt->graph->max_values.x)
            plt->graph->max_values.x = plt->graph->points[i].x;

        if (plt->graph->points[i].y > plt->graph->max_values.y)
            plt->graph->max_values.y = plt->graph->points[i].y;

        if (plt->graph->points[i].x < plt->graph->min_values.x)
            plt->graph->min_values.x = plt->graph->points[i].x;

        if (plt->graph->points[i].y < plt->graph->min_values.y)
            plt->graph->min_values.y = plt->graph->points[i].y;
    }
}

static inline __attribute__((always_inline)) void init_var(my_plot_t *plt)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    find_extrema(plt);

    plt->graph->ratio.x = (tmp_vec.x - plt->theme->radius*2) / 20;
    plt->graph->ratio.y = (tmp_vec.y - plt->theme->radius*2) / 20;

    plt->graph->is_dragged = sfFalse;
    plt->graph->shift.x = 0;
    plt->graph->shift.y = 0;
    plt->graph->last_shift.x = 0;
    plt->graph->last_shift.y = 0;
}

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt)
{
    plt->window = sfRenderWindow_create(*md, title, sfDefaultStyle, NULL);
    plt->event = evt;
    init_var(plt);
    compute_pts(plt);
}
