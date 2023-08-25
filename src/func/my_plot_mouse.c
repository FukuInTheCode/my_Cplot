#include "../../includes/my.h"

void my_plot_handle_mouse(my_fig_t *fig)
{
    fig->plot->shift.x = fig->shift_save.x;
    fig->plot->shift.y = fig->shift_save.y;
    sfVector2i mouse_vec = sfMouse_getPosition(fig->window);
    sfMouseButton left_btn = sfMouseLeft;

    if (fig->is_moving == sfFalse && sfMouse_isButtonPressed(left_btn)) {
        fig->is_moving = sfTrue;
        fig->mouse_vec_save.x = mouse_vec.x;
        fig->mouse_vec_save.y = mouse_vec.y;
    } else if (fig->is_moving == sfTrue) {
        fig->plot->shift.x -= fig->mouse_vec_save.x - mouse_vec.x;
        fig->plot->shift.y += fig->mouse_vec_save.y - mouse_vec.y;
    }

    if (!sfMouse_isButtonPressed(left_btn) && fig->is_moving == sfTrue) {
        fig->is_moving = sfFalse;
        fig->shift_save.x = fig->plot->shift.x;
        fig->shift_save.y = fig->plot->shift.y;
    }
}