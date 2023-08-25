#include "../../includes/my.h"

static void create_window(my_fig_t *fig)
{
    volatile sfVideoMode mode = {500 * SCALE, 500 * SCALE, 32};
    fig->window = sfRenderWindow_create(mode, fig->title, \
        sfClose, NULL);
}

static void init_variable(my_fig_t *fig)
{
    fig->is_moving = sfFalse;
    fig->shift_save.x = 0;
    fig->shift_save.y = 0;
}

void my_fig_create(my_fig_t *fig)
{
    init_variable(fig);
    create_window(fig);
}
