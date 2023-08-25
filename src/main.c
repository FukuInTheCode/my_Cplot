#include "../includes/my.h"

int main(void)
{
    hello2();
    sfVideoMode mode = {1000, 1000, 32};
    char *title = "Hello World";
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    sfEvent event;
    double r = 10;
    sfVector2f points[] = {
        {0, 0},
        {1, 2},
        {2, 3},
        {3, 4},
        {-1, 2}
    };
    sfVector2u tmp_vec = sfRenderWindow_getSize(window);
    sfVector2f max_values = {0, 0};
    sfVector2f min_values = {0, 0};
    for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
        if (points[i].x > max_values.x) max_values.x = points[i].x;
        if (points[i].y > max_values.y) max_values.y = points[i].y;
        if (points[i].x < min_values.x) min_values.x = points[i].x;
        if (points[i].y < min_values.y) min_values.y = points[i].y;
    }
    printf("max: %f, %f\n", max_values.x, max_values.y);
    printf("min: %f, %f\n", min_values.x, min_values.y);

    sfVector2f interval = {
        max_values.x - min_values.x,
        max_values.y - min_values.y,
    };
    printf("interval: %f, %f\n", interval.x, interval.y);
    sfVector2f ratio = {
        (tmp_vec.x - r*2) / interval.x,
        (tmp_vec.y - r*2) / interval.y
    };
    printf("ratio: %f, %f\n", ratio.x, ratio.y);
    for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
        points[i].x *= ratio.x;
        points[i].y *= ratio.y;
        points[i].y = (tmp_vec.y - r*2) - points[i].y;
        points[i].x += tmp_vec.x / 2.f;
        points[i].y -= tmp_vec.y / 2.f;
    }
    for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
        printf("%zu: %f, %f\n", i, points[i].x, points[i].y);
    }

    sfBool is_graph_drag = sfFalse;

    sfVector2i shift = {0, 0};

    sfVector2i last_shift = {0, 0};

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (!is_graph_drag) {
                is_graph_drag = sfTrue;
                last_shift = sfMouse_getPosition(window);
            }
            else {
                sfVector2i mouse_vec = sfMouse_getPosition(window);
                shift.x += mouse_vec.x - last_shift.x;
                shift.y += mouse_vec.y - last_shift.y;
                last_shift = mouse_vec;
            }
        } else
            is_graph_drag = sfFalse;

        sfRenderWindow_clear(window, sfBlack);
        for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
            sfCircleShape *current_pts = sfCircleShape_create();
            sfCircleShape_setFillColor(current_pts, sfBlue);
            sfCircleShape_setRadius(current_pts, r);
            sfVector2f tmp_pts = points[i];
            tmp_pts.x += shift.x;
            tmp_pts.y += shift.y;
            sfCircleShape_setPosition(current_pts, tmp_pts);
            sfRenderWindow_drawCircleShape(window, current_pts, NULL);
            sfCircleShape_destroy(current_pts);
        }
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);

    return 0;
}
