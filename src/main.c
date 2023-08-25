#include "../includes/my.h"

int main(void)
{
    hello2();
    sfVideoMode mode = {1000, 1000, 32};
    char *title = "Hello World";
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    sfEvent event;
    sfVector2f points[] = {
        {1, 2},
        {2, 3},
        {3, 4}
    };
    sfVector2u tmp_vec = sfRenderWindow_getSize(window);
    for (size_t i = 0; i < 3; ++i) {
        points.x += 
        printf("%f, %f\n", points[i].x, points[i].y);
    }
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);
        for (size_t i = 0; i < 3; ++i) {
            sfCircleShape *current_pts = sfCircleShape_create();
            sfCircleShape_setFillColor(current_pts, sfBlue);
            sfCircleShape_setRadius(current_pts, 10);
            sfCircleShape_setPosition(current_pts, points[i]);
            sfRenderWindow_drawCircleShape(window, current_pts, NULL);
            sfCircleShape_destroy(current_pts);
        }
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);

    return 0;
}
