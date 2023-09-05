#include "../../includes/my.h"

static void vertical_shift(my_plot_t *plt)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl))
            plt->shift.x -= 10;
        else
            plt->shift.x -= 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl))
            plt->shift.x += 10;
        else
            plt->shift.x += 1;
    }
}

static void hor_shift(my_plot_t *plt)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl))
            plt->shift.y -= 10;
        else
            plt->shift.y -= 1;
    } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl))
            plt->shift.y += 10;
        else
            plt->shift.y += 1;
    }
}

void my_plot_handle_shift(my_plot_t *plt)
{
    vertical_shift(plt);
    hor_shift(plt);

    if (sfKeyboard_isKeyPressed(sfKeyO)) {
        plt->shift.x = 0;
        plt->shift.y = 0;
        plt->zoom.x = 0;
        plt->zoom.y = 0;
    }
}
