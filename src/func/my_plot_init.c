#include "../../includes/my.h"

static double find_max(double *arr, size_t size)
{
    if (size == 0 || arr == NULL)
        return 0.0;

    double max_value = arr[0];

    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max_value)
            max_value = arr[i];
    }
    return max_value;
}

static double find_min(double *arr, size_t size)
{
    if (size == 0 || arr == NULL)
        return 0.0;

    double min_value = arr[0];

    for (size_t i = 1; i < size; i++) {
        if (arr[i] < min_value)
            min_value = arr[i];
    }

    return min_value;
}

void my_plot_init(my_plot_t *plot)
{
    plot->max_x = find_max(plot->xs, plot->num);
    plot->max_y = find_max(plot->ys, plot->num);
    plot->min_x = find_min(plot->xs, plot->num);
    plot->min_y = find_min(plot->ys, plot->num);
    printf("%f, %f, %f, %f\n", plot->max_x, plot->max_y, plot->min_x, plot->min_y);
}