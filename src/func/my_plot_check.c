#include "../../includes/my.h"

sfBool my_plot_is_onscreen(my_plot_t *plt, sfVector2f coords,\
                            my_obj_type_t type)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    sfVector2f upper_border = {0, 0};
    sfVector2f lower_border = {tmp_vec.x, tmp_vec.y};
    if (type == pts) {
        upper_border.x -= plt->theme->radius * 2;
        upper_border.y -= plt->theme->radius * 2;
    }
    if (coords.x < upper_border.x) return sfFalse;
    if (coords.y < upper_border.y) return sfFalse;
    if (coords.y > lower_border.y) return sfFalse;
    if (coords.x > lower_border.x) return sfFalse;

    return sfTrue;
}
