#include "../../includes/my.h"

static inline __attribute__((always_inline))\
    sfBool is_define(my_func_t *f, double x) {
    if (f->left_type == integer && x < f->left)
        return sfFalse;
    if (f->right_type == integer && x > f->right)
        return sfFalse;

    for (size_t i = 0; i < f->n_undef; ++i) {
        if (x == f->undefined[i])
            return sfFalse;
    }
    return sfTrue;
}

void my_plot_func(my_plot_t *plt)
{
    double steps = 20.0 / plt->graph->st_func.max_pts;
    for (size_t i = 0; i < plt->graph->st_func.max_pts; ++i) {
        double x = -10 - plt->graph->shift.x / plt->graph->ratio.x + i * steps;
        plt->graph->points[i].x = x;
        if (!is_define(&(plt->graph->st_func.func), x))
            plt->graph->points[i].y = sfRenderWindow_getSize(plt->window).y;
        else
            plt->graph->points[i].y = plt->graph->st_func.func.f(x);
    }
    compute_pts(plt);
}
