#include "../../includes/my.h"

static inline __attribute__ ((always_inline)) init_var(my_plot_t *plt)
{
    // ....
}

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt)
{
    plt->window = sfRenderWindow_create(*md, title, sfDefaultStyle, NULL);
    plt->event = evt;
}