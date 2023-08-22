#include "../../includes/my.h"

void my_fig_create(my_fig_t *fig)
{
    volatile sfVideoMode mode = {500 * SCALE, 500 * SCALE, 32};
    fig->window = sfRenderWindow_create(mode, fig->title, \
        sfResize | sfClose, NULL);

    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    fig->plot->ratio.x = tmp_vec.x - 20;
    fig->plot->ratio.y = tmp_vec.y - 20;
    my_plot_init(fig->plot);
}
