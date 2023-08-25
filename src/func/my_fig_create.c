#include "../../includes/my.h"

static void create_window(my_fig_t *fig)
{
    sfVideoMode mode = {500 * SCALE, 500 * SCALE, 32};
    fig->window = sfRenderWindow_create(mode, fig->title, \
        sfClose, NULL);
}

static void calc_ratio(my_fig_t *fig)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    if (fig->plot->type != function_pts) {
        my_fig_set_exvalues(fig);
        double min_x = fig->plot->min_x;

        fig->plot->ratio.x = tmp_vec.x - fig->ui->point_radius * 2 -\
                                (min_x != 0 && fig->plot->max_x != 0 ? 0 : 40);

        fig->plot->ratio.x /= fig->plot->max_x - min_x;

        double min_y = fig->plot->min_y;
        fig->plot->ratio.y = tmp_vec.y - fig->ui->point_radius * 3 -\
                            (min_y != 0 && fig->plot->max_y != 0 ? 0 : 40);
        fig->plot->ratio.y /= fig->plot->max_y - min_y;
    } else {
        fig->plot->ratio.x = tmp_vec.x - fig->ui->point_radius * 2;
        fig->plot->ratio.x /= 20;
        fig->plot->ratio.x = tmp_vec.y - fig->ui->point_radius * 2;
        fig->plot->ratio.x /= ;
    }
}

static void init_variable(my_fig_t *fig)
{
    fig->is_moving = sfFalse;

    fig->shift_save.x = 0;
    fig->shift_save.y = 0;

    fig->plot->shift.x = 0;
    fig->plot->shift.y = 0;

    calc_ratio(fig);
}

void my_fig_create(my_fig_t *fig)
{
    create_window(fig);
    init_variable(fig);
}
