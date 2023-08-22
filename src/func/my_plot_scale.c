#include "../../includes/my.h"

static double this_find_max(double *arr, size_t size)
{
    if (size == 0 || arr == NULL)
        return 0.0;

    double max_value = 0;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] > max_value)
            max_value = arr[i];
    }
    return max_value;
}

static double this_find_min(double *arr, size_t size)
{
    if (size == 0 || arr == NULL)
        return 0.0;

    double min_value = 0;

    for (size_t i = 0; i < size; i++) {
        if (arr[i] < min_value)
            min_value = arr[i];
    }

    return min_value;
}

void my_plot_calc_scale(my_fig_t *fig)
{
    my_plot_t *plot = fig->plot;

    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);

    plot->ratio.x = tmp_vec.x - fig->ui->point_radius * 2;
    plot->ratio.y = tmp_vec.y - fig->ui->point_radius * 2;

    plot->min_x = this_find_min(plot->xs, plot->num);
    plot->min_y = this_find_min(plot->ys, plot->num);
    plot->ratio.x /= this_find_max(plot->xs, plot->num) - \
                            plot->min_x;
    plot->ratio.y /= this_find_max(plot->ys, plot->num) - \
                            plot->min_y;
    plot->min_x = my_abs(plot->min_x) * plot->ratio.x;
    plot->min_y = my_abs(plot->min_y) * plot->ratio.y;
}