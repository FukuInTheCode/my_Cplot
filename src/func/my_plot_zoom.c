#include "../../includes/my.h"

static void handle_zoom(my_plot_t *plt)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl) &&\
            sfKeyboard_isKeyPressed(sfKeyLShift)) {
            plt->zoom.x += 50;
            plt->zoom.y += 50;
        } else if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            plt->zoom.x += 10;
            plt->zoom.y += 10;
        } else if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
            plt->zoom.x += 5;
            plt->zoom.y += 5;
        } else {
            plt->zoom.x += 1;
            plt->zoom.y += 1;
        }
    }
}

static void handle_dezoom(my_plot_t *plt)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        if (sfKeyboard_isKeyPressed(sfKeyLControl) &&\
            sfKeyboard_isKeyPressed(sfKeyLShift)) {
            plt->zoom.x -= 50;
            plt->zoom.y -= 50;
        } else if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            plt->zoom.x -= 10;
            plt->zoom.y -= 10;
        } else if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
            plt->zoom.x -= 5;
            plt->zoom.y -= 5;
        } else {
            plt->zoom.x -= 1;
            plt->zoom.y -= 1;
        }
    }
    plt->zoom.x = my_max_between(plt->zoom.x, -plt->ratio.x + 1e-2);
    plt->zoom.y = my_max_between(plt->zoom.y, -plt->ratio.y + 1e-2);
}

void my_plot_handle_zoom(my_plot_t *plt)
{
    handle_dezoom(plt);
    handle_zoom(plt);
}
