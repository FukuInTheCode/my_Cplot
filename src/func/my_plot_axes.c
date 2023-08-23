#include "../../includes/my.h"

// static void my_plot_axes_graduation(my_fig_t *fig)
// {

// }

void my_plot_axes(my_fig_t *fig)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    sfVertex line[] = {
        {{0, fig->plot->axe1}, sfWhite},
        {{tmp_vec.x, fig->plot->axe1}, sfWhite}
    };

    sfRenderWindow_drawPrimitives(fig->window, line, 2, sfLines, NULL);
    sfVertex line2[] = {
        {{fig->plot->axe2, 0}, sfWhite},
        {{fig->plot->axe2, tmp_vec.y}, sfWhite}
    };

    sfRenderWindow_drawPrimitives(fig->window, line2, 2, sfLines, NULL);
    my_plot_axes_graduation(fig);
}
