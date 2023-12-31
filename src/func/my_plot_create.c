#include "../../includes/my.h"

void my_plot_create(my_plot_t *plt, my_theme_t *th)
{
    sfVideoMode mode = {1000, 1000, 32};
    plt->window = sfRenderWindow_create(mode, plt->title, sfDefaultStyle,\
                                                                        NULL);
    plt->shift.x = 0;
    plt->shift.y = 0;
    plt->mouse_save.x = 0;
    plt->mouse_save.y = 0;
    plt->zoom.x = 0;
    plt->zoom.y = 0;
    plt->th = th;
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);
    plt->ratio.x = window_size.x / (20. * 0.1) / 2;
    plt->ratio.y = window_size.y / (20. * 0.1)  / 2;
}
