#include "../../includes/my.h"

static inline sfVector2f calc_pos_vec(my_fig_t *fig, size_t i)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);

    sfVector2f pos = {
        .x = fig->plot->xs[i] * fig->plot->ratio.x +\
                fig->plot->hor_shift,
        .y = tmp_vec.y - fig->plot->ys[i] * fig->plot->ratio.y -\
                fig->ui->point_radius * 3 - fig->plot->ver_shift
    };

    if (fig->plot->axe2 == 40 + fig->ui->point_radius) pos.x += 40;

    if (fig->plot->axis.x == tmp_vec.y - 40)
        pos.y -= 40 - fig->ui->point_radius * 2;

    return pos;
}

static inline sfBool is_onscreen(my_fig_t *fig, sfVector2f pos)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    if (pos.x > tmp_vec.x ||
        pos.x < -2 * fig->ui->point_radius ||
        pos.y > tmp_vec.y || pos.y < -2 * fig->ui->point_radius)
        return sfFalse;

    return sfTrue;
}

void my_plot_point(my_fig_t *fig)
{
    my_fig_calc_scale(fig);
    for (size_t i = 0; i < fig->plot->num; i++) {
        sfVector2f pos = calc_pos_vec(fig, i);
        if (!is_onscreen(fig, pos)) continue;

        sfCircleShape *current_point = sfCircleShape_create();
        sfCircleShape_setRadius(current_point, fig->ui->point_radius);

        sfCircleShape_setPosition(current_point, pos);
        sfCircleShape_setFillColor(current_point, fig->plot->ys[i] != 0 ? \
                                    fig->ui->point : sfBlue);
        sfRenderWindow_drawCircleShape(fig->window, current_point, NULL);
        sfCircleShape_destroy(current_point);
    }
}