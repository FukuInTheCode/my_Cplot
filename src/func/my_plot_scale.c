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

static inline void set_extreme_values(my_fig_t *fig)
{
    fig->plot->min_x = this_find_min(fig->plot->xs, fig->plot->num);
    fig->plot->max_x = this_find_max(fig->plot->xs, fig->plot->num);
    fig->plot->min_y = this_find_min(fig->plot->ys, fig->plot->num);
    fig->plot->max_y = this_find_max(fig->plot->ys, fig->plot->num);
}

void my_fig_calc_scale(my_fig_t *fig)
{
    set_extreme_values(fig);
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    fig->plot->axis.x = tmp_vec.y;
    fig->plot->axis.y = 40;
    double min_x = fig->plot->min_x;
    double min_y = fig->plot->min_y;
    fig->plot->ratio.x = tmp_vec.x - fig->ui->point_radius * 2 -\
                            (min_x != 0 && fig->plot->max_x != 0 ? 0 : 40);
    fig->plot->ratio.y = tmp_vec.y - fig->ui->point_radius * 3 -\
                            (min_y != 0 && fig->plot->max_y != 0 ? 0 : 40);
    fig->plot->ratio.x /= fig->plot->max_x - min_x;
    fig->plot->ratio.y /= fig->plot->max_y - min_y;
    fig->plot->shift.x += my_abs(min_x) * fig->plot->ratio.x;
    fig->plot->axis.y = min_x != 0 || \
            fig->plot->shift.x != 0 ? fig->plot->shift.x : 40;
    fig->plot->axis.y += fig->ui->point_radius;
    fig->plot->shift.y += my_abs(min_y) * fig->plot->ratio.y;
    fig->plot->axis.x -= min_y != 0 || fig->plot->shift.y != 0 ? \
}
