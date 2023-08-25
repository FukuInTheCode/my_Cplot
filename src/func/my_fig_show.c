#include "../../includes/my.h"

void my_fig_show(my_fig_t *fig)
{
    while (sfRenderWindow_isOpen(fig->window)) {
        while (sfRenderWindow_pollEvent(fig->window, fig->event))
            my_fig_handle_event(fig);

        my_plot(fig);
    }
    sfRenderWindow_destroy(fig->window);
}
