#include "../includes/SFML/Graphics.h"

int main(void)
{
    sfVideoMode mode = {2000, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "SFML window", \
        sfResize | sfClose, NULL);
    sfEvent event;

    sfMouseButton left = sfMouseLeft;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
