#include "../../includes/my.h"


void my_fig_show(my_fig_t *fig)
{
    while (sfRenderWindow_isOpen(fig->window)) {
        while (sfRenderWindow_pollEvent(fig->window, fig->event)) {
            if (fig->event->type == sfEvtClosed){
                printf("test\n");
                sfRenderWindow_close(fig->window);
            }
        }
        sfRenderWindow_clear(fig->window, fig->colors->background);
        sfRenderWindow_display(fig->window);
    }
    sfRenderWindow_destroy(fig->window);
}
