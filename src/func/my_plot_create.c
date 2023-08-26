#include "../../includes/my.h"

static inline __attribute__((always_inline)) void compute_pts(my_plot_t *plt)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    for (size_t i = 0; i < plt->graph->data_num; ++i) {
        plt->graph->points[i].y *= plt->graph->ratio.y;
        plt->graph->points[i].x *= plt->graph->ratio.x;
        plt->graph->points[i].y = (tmp_vec.y - plt->theme->radius*2) -\
                                    plt->graph->points[i].y;
        plt->graph->points[i].x += tmp_vec.x / 2.f;
        plt->graph->points[i].y -= tmp_vec.y / 2.f;
    }
}

static inline __attribute__((always_inline)) void find_extrema(my_plot_t *plt)
{
    plt->graph->max_values.x = 0;
    plt->graph->max_values.y = 0;
    plt->graph->min_values.x = 0;
    plt->graph->min_values.y = 0;
    printf("%lld\n", plt->graph->data_num);
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

    plt->graph->interval.y = plt->graph->max_values.y - plt->graph->min_values.y;
    plt->graph->interval.x = plt->graph->max_values.x - plt->graph->min_values.x;

    plt->graph->ratio.x = (tmp_vec.x - plt->theme->radius*2) / plt->graph->interval.x;
    plt->graph->ratio.y = (tmp_vec.y - plt->theme->radius*2) / plt->graph->interval.y;

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
