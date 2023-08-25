#include "../../includes/my.h"

static void generate_points(my_fig_t *fig, double start, double end)
{
    if (start >= end || fig->plot->num == 1) {
        fprintf(stderr, "Error: Invalid parameters.\n");
        return;
    }

    double increment = (end - start) / (fig->plot->num - 1);
    for (int i = 0; i < fig->plot->num; i++) {
        fig->plot->xs[i] = start + i * increment;
        fig->plot->ys[i] = fig->plot->func(fig->plot->xs[i]);
    }
}

void my_plot_function(my_fig_t *fig)
{
    generate_points(fig, -10, 10);
    // for (size_t i = 0; i < fig->plot->num; ++i)
    //     printf("%f, %f\n", fig->plot->xs[i], fig->plot->ys[i]);
    my_plot_point(fig);
}