#include "../../includes/my.h"

void my_plot_handle_mouse(my_plot_t *plt)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (plt->is_pressed) {
            sfVector2i tmp = sfMouse_getPosition(NULL);
            plt->shift.x += tmp.x - plt->mouse_save.x;
            plt->shift.y += tmp.y - plt->mouse_save.y;
            plt->mouse_save = tmp;
        } else {
            plt->mouse_save = sfMouse_getPosition(NULL);
            plt->is_pressed = true;
        }
    } else if (plt->is_pressed)
        plt->is_pressed = false;

}
