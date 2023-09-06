#include "../../includes/my.h"

static void create(my_graph_t *g, uint32_t n, my_theme_t *th)
{
    g->xs = calloc(n, sizeof(double));
    g->ys = calloc(n, sizeof(double));
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

void my_graph_create_f2(my_graph_t *g, uint32_t n, my_theme_t *th, func2 f)
{
    g->type = function2;
    create(g, n, th);
    g->pts_n = 0;
    g->f2 = f;
}
