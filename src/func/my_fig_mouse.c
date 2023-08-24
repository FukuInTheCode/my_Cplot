#include "../../includes/my.h"

void my_plot_handle_mouse(my_fig_t *fig)
{
    sfVector2i mouse_vec = sfMouse_getPosition(fig->window);
    sfMouseButton left_btn = sfMouseLeft;
    if (fig->is_moving == sfFalse && sfMouse_isButtonPressed(left_btn)) {
        fig->is_moving = sfTrue;
        printf("%i, %i\n", mouse_vec.x, mouse_vec.y);
    } else if (fig->is_moving == sfTrue && !sfMouse_isButtonPressed(left_btn)) {
        fig->is_moving = sfFalse;
        printf("%i, %i\n", mouse_vec.x, mouse_vec.y);
    }
}