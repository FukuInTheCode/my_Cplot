#include "../../includes/my.h"

void my_plot_func(my_plot_t *plt)
{
    double steps = 20.0 / plt->graph->st_func.max_pts;
    for (size_t i = 0; i < plt->graph->st_func.max_pts; ++i) {
        plt->graph->points[i].x = -10 - plt->graph->shift.x / plt->graph->ratio.x + i * steps;
        plt->graph->points[i].y = plt->graph->st_func.func.f(plt->graph->points[i].x);
    }
    compute_pts(plt);
}