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

void my_fig_calc_scale(my_fig_t *fig)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    fig->plot->axe1 = tmp_vec.y;
    fig->plot->axe2 = 40;
    double min_x = this_find_min(fig->plot->xs, fig->plot->num);
    double min_y = this_find_min(fig->plot->ys, fig->plot->num);
    fig->plot->ratio.x = tmp_vec.x - fig->ui->point_radius * 2 -\
                            (min_x != 0 ? 0 : 40);
    fig->plot->ratio.y = tmp_vec.y - fig->ui->point_radius * 2 -\
                            (min_y != 0 ? 0 : 40);
    fig->plot->ratio.x /= this_find_max(fig->plot->xs, fig->plot->num) - min_x;
    fig->plot->ratio.y /= this_find_max(fig->plot->ys, fig->plot->num) - min_y;
    fig->plot->margin_left = my_abs(min_x) * fig->plot->ratio.x;
    fig->plot->axe2 = min_x != 0 ? fig->plot->margin_left : 40;
    fig->plot->margin_up = my_abs(min_y) * fig->plot->ratio.y;
    fig->plot->axe1 -= min_y != 0 ? (fig->ui->point_radius * 2 +\
                            fig->plot->margin_up) : 40;
}