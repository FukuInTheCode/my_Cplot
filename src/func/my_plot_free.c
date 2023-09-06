#include "../../includes/my.h"

void my_plot_free(my_plot_t *plt)
{
    sfRenderWindow_destroy(plt->window);
}
