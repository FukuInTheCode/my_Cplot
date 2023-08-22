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

void my_plot_init(my_plot_t *plot)
{
    plot->min_x = this_find_min(plot->xs, plot->num);
    plot->min_y = this_find_min(plot->ys, plot->num);
    plot->ratio.x /= this_find_max(plot->xs, plot->num) - \
                            plot->min_x;
    plot->ratio.y /= this_find_max(plot->ys, plot->num) - \
                            plot->min_y;
    plot->min_x = my_abs(plot->min_x) * plot->ratio.x;
    plot->min_y = my_abs(plot->min_y) * plot->ratio.y;
}