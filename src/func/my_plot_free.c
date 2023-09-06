#include "../../includes/my.h"

void my_plot_free(my_plot_t *plt)
{
    sfRenderWindow_destroy(plt->window);

    if(plt->gs_n == 0)
        return;

    for (uint32_t i = 0; i < plt->gs_n; ++i) {
        free(plt->gs[i]->xs);
        free(plt->gs[i]->ys);
    }
    free(plt->gs);
}
