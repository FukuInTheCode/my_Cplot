#include "../../includes/my.h"



void my_plot_handle_zoom(my_plot_t *plt)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            plt->zoom.x += 10;
            plt->zoom.y += 10;
        } else {
            plt->zoom.x += 1;
            plt->zoom.y += 1;
        }

    } else if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            plt->zoom.x = my_max_between(plt->zoom.x - 10, -plt->ratio.x + 1e-2);
            plt->zoom.y = my_max_between(plt->zoom.y - 10, -plt->ratio.y + 1e-2);
        } else {
            plt->zoom.x = my_max_between(plt->zoom.x - 1, -plt->ratio.x + 1e-2);
            plt->zoom.y = my_max_between(plt->zoom.y - 1, -plt->ratio.y + 1e-2);
        }
    }
}
