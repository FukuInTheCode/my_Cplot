#include "../../includes/my.h"

void my_plot_handle_events(my_plot_t *plt)
{
    while (sfRenderWindow_pollEvent(plt->window, &(plt->event))) {
        if (plt->event.type == sfEvtClosed) {
            sfRenderWindow_close(plt->window);
        }
    }
}
