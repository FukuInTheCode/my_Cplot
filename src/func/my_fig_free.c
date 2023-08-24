#include "../../includes/my.h"

void my_fig_free(my_fig_t *fig)
{
    sfRenderWindow_destroy(fig->window);
}
