#include "../../includes/my.h"

void my_plot_func(my_plot_t *plt, my_graph_t *g)
{
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);
    double x_i = (g->th->radius - plt->shift.x - window_size.x / 2) / (plt->ratio.x + plt->zoom.x);
    double x_end = (g->th->radius - plt->shift.x + window_size.x / 2) / (plt->ratio.x + plt->zoom.x);
    double x_steps = (x_end - x_i) / g->max_pts_n;
    g->pts_n = 0;
    for (; x_i < x_end; x_i += x_steps) {
        g->xs[g->pts_n] = x_i;
        g->ys[g->pts_n] = g->f(x_i);
        (g->pts_n)++;
    }
}
