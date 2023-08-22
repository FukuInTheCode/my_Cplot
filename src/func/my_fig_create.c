#include "../../includes/my.h"

void my_fig_create(my_fig_t *fig)
{
    volatile sfVideoMode mode = {500 * SCALE, 500 * SCALE, 32};
    fig->window = sfRenderWindow_create(mode, fig->title, \
        sfClose, NULL);
}
