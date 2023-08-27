#include "../../includes/my.h"

static inline __attribute__((always_inline)) void find_extrema(my_plot_t *plt, my_graph_t *g)
{
    g->max_values.x = 0;
    g->max_values.y = 0;
    g->min_values.x = 0;
    g->min_values.y = 0;
    for (size_t i = 0; i < g->data_num; ++i) {
        if (g->points[i].x > g->max_values.x)
            g->max_values.x = g->points[i].x;

        if (g->points[i].y > g->max_values.y)
            g->max_values.y = g->points[i].y;

        if (g->points[i].x < g->min_values.x)
            g->min_values.x = g->points[i].x;

        if (g->points[i].y < g->min_values.y)
            g->min_values.y = g->points[i].y;
    }
}

static inline __attribute__((always_inline)) void init_var(my_plot_t *plt, my_graph_t *g)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    find_extrema(plt, g);
    if ((tmp_vec.x - g->theme->graph.radius * 2) / 20 > plt->ratio.x)
        plt->ratio.x = (tmp_vec.x - g->theme->graph.radius * 2) / 20;
    if ((tmp_vec.y - g->theme->graph.radius * 2) / 20 > plt->ratio.y)
        plt->ratio.y = (tmp_vec.y - g->theme->graph.radius * 2) / 20;
}

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt)
{
    plt->window = sfRenderWindow_create(*md, title, sfDefaultStyle, NULL);
    plt->event = evt;

    plt->is_dragged = sfFalse;
    plt->shift.x = 0;
    plt->shift.y = 0;
    plt->last_shift.x = 0;
    plt->last_shift.y = 0;
    plt->ratio.x = 0;
    plt->ratio.y = 0;

    for (uint32_t i = 0; i < plt->graph_n; ++i) {
        init_var(plt, plt->graph[i]);
        compute_pts(plt, plt->graph[i]);
    }
}
