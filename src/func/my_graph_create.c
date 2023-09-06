#include "../../includes/my.h"

void my_graph_create_pts(my_graph_t *g, uint32_t n, my_theme_t *th)
{
    g->type = points;
    g->xs = calloc(double, n);
    g->ys = calloc(double, n);
    g->pts_n = n;
    g->max_pts_n = n;
    g->th = th;
}
