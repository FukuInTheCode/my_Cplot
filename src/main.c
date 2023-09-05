#include "../includes/my.h"

int main(void)
{

    

    sfVector2f ratio = {

    }

    my_plot_t plt = {.title = "Test"};
    plt.mode.height = 1000;
    plt.mode.width = 1000;
    plt.mode.bitsPerPixel = 32;
    plt.window = sfRenderWindow_create(plt.mode, plt.title, sfDefaultStyle, NULL);

    while (sfRenderWindow_isOpen(plt.window)) {

        while (sfRenderWindow_pollEvent(plt.window, &(plt.event))) {
            if (plt.event.type == sfEvtClosed) {
                sfRenderWindow_close(plt.window);
            }
        }

        sfRenderWindow_clear(plt.window, sfWhite);
        for (uint32_t i = 0; i < )

    }

    sfRenderWindow_destroy(plt.window);
    return 0;
}
