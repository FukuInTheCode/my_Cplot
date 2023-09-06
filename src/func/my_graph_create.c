#include "../../includes/my.h"

static void create(my_graph_t *g, uint32_t n, my_theme_t *th)
{
    g->xs = calloc(double, n);
    g->ys = calloc(double, n);
    g->pts_n = n;
    g->max_pts_n = n;
    g->th = th;
}

void my_graph_create_pts(my_graph_t *g, uint32_t n, my_theme_t *th)
{
    g->type = points;
    create(g, n, th);
}

void my_graph_create_f(my_graph_t *g, uint32_t n, my_theme_t *th, func f)
{
    g->type = function;
    create(g, n, th);
    g->pts_n = 0;
    g->f = f;
}
