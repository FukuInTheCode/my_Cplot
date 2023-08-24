#include "../../includes/my.h"

void my_fig_handle_event(my_fig_t *fig)
{
    if (fig->event->type == sfEvtClosed) {
        sfRenderWindow_close(fig->window);
    }
}