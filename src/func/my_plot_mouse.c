#include "../../includes/my.h"

void my_plot_handle_mouse(my_plot_t *plt)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (!plt->graph->is_dragged) {
            plt->graph->is_dragged = sfTrue;
            plt->graph->last_shift = sfMouse_getPosition(plt->window);
        }
        else {
            sfVector2i mouse_vec = sfMouse_getPosition(plt.window);
            plt->graph->shift.x += mouse_vec.x - plt->graph->last_shift.x;
            plt->graph->shift.y += mouse_vec.y - plt->graph->last_shift.y;
            plt->graph->last_shift = mouse_vec;
        }
    } else
        plt->graph->is_dragged = sfFalse;
}
