#include "../../includes/my.h"

void my_graph_set_pts(my_graph_t *g, double *xs, double *ys)
{
    for (uint32_t i = 0; i < g->pts_n; ++i) {
        g->xs[i] = xs[i];
        g->ys[i] = ys[i];
    }
}
