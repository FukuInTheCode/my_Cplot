#include "../../includes/my.h"

static void my_plot_axes_graduation_horizontal(my_fig_t *fig)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    double steps = fig->plot->max_x / 10 * fig->plot->ratio.x;
    double i = fig->plot->axe2 + steps;
    for ( ; i < tmp_vec.y && i != fig->plot->axe2; i += steps) {
        sfVertex line[] = {
        {{i, fig->plot->axe1 - 5}, sfWhite},
        {{i, fig->plot->axe1 + 5}, sfWhite}
        };
        sfRenderWindow_drawPrimitives(fig->window, line, 2, sfLines, NULL);
    }
    steps = fig->plot->min_x / 10 * fig->plot->ratio.x;
    i = fig->plot->axe2 + steps;
    for ( ; i > 0 && i != fig->plot->axe2; i += steps) {
        sfVertex line[] = {
        {{i, fig->plot->axe1 - 5}, sfWhite},
        {{i, fig->plot->axe1 + 5}, sfWhite}
        };
        sfRenderWindow_drawPrimitives(fig->window, line, 2, sfLines, NULL);
    }
}

static void my_plot_axes_graduation_vertical(my_fig_t *fig)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(fig->window);
    double steps = fig->plot->max_y / 10 * fig->plot->ratio.y;
    double i = fig->plot->axe1 - steps;
    for ( ; i > 0 && i != fig->plot->axe1; i -= steps) {
        sfVertex line[] = {
        {{fig->plot->axe2 - 5, i}, sfWhite},
        {{fig->plot->axe2 + 5, i}, sfWhite}
        };
        sfRenderWindow_drawPrimitives(fig->window, line, 2, sfLines, NULL);
    }
    steps = fig->plot->min_y / 10 * fig->plot->ratio.y;
    i = fig->plot->axe1 - steps;
    for ( ; i < tmp_vec.y && i != fig->plot->axe1; i -= steps) {
        sfVertex line[] = {
        {{fig->plot->axe2 - 5, i}, sfWhite},
        {{fig->plot->axe2 + 5, i}, sfWhite}
        };
        sfRenderWindow_drawPrimitives(fig->window, line, 2, sfLines, NULL);
    }
}

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
    my_plot_axes_graduation_horizontal(fig);
    my_plot_axes_graduation_vertical(fig);
}
