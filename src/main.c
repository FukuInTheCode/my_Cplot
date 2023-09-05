#include "../includes/my.h"

int main(void)
{

    // main

    uint32_t n = 8;

    double xs[] = { 0, 2, -1, 0, 1, 2, 3, 4 };
    double ys[] = { 0, 3, 2, 3, 1, 2, 3, 4 };

    char *title = "Test";
    sfEvent event;
    sfVideoMode mode = {1000, 1000, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);

    // init

    sfVector2f shift = {0, 0};

    sfVector2i mouse_vec_save = {0, 0};

    uint8_t is_pressed = 0;

    // calc ratio
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfVector2f ratio = {
        (window_size.x - 10) / (my_max(xs, n) - my_min(xs, n) + 0.1) / 2,
        (window_size.y - 10) / (my_max(ys, n) - my_min(ys, n) + 0.1) / 2
    };


    // show
    while (sfRenderWindow_isOpen(window)) {
        // event handling
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        // plotting

        sfRenderWindow_clear(window, sfBlack);

        // mouse handling
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (is_pressed == 1) {
                sfVector2i tmp = sfMouse_getPosition(NULL);
                shift.x += tmp.x - mouse_vec_save.x;
                shift.y += tmp.y - mouse_vec_save.y;
                mouse_vec_save = tmp;
            } else {
                mouse_vec_save = sfMouse_getPosition(NULL);
                is_pressed = 1;
            }
        } else if (is_pressed == 1)
            is_pressed = 0;

        // zoom handling
        if (sfKeyboard_isKeyPressed(sfKeyA)) {
            ratio.x += 1;
            ratio.y += 1;
        } else if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            ratio.x = my_max_between(ratio.x - 1, 0);
            ratio.y = my_max_between(ratio.y - 1, 0);;
        }

        // keyboard moving handling
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                shift.x -= 10;
            else
                shift.x -= 1;
        } else if (sfKeyboard_isKeyPressed(sfKeyRight))
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                shift.x += 10;
            else
                shift.x += 1;

        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                shift.y -= 10;
            else
                shift.y -= 1;
        } else if (sfKeyboard_isKeyPressed(sfKeyDown))
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                shift.y += 10;
            else
                shift.y += 1;

        if (sfKeyboard_isKeyPressed(sfKeyO)) {
            shift.x = 0;
            shift.y = 0;
            ratio.x = (window_size.x - 10) / (my_max(xs, n) - my_min(xs, n) + 0.1) / 2;
            ratio.y = (window_size.y - 10) / (my_max(ys, n) - my_min(ys, n) + 0.1) / 2;
        }

        // axis plotting
        sfVertex line2[] = {
            {{0, window_size.y / 2 + shift.y}, sfWhite},
            {{window_size.x, window_size.y / 2 + shift.y}, sfWhite}
        };

        sfVertex line[] = {
            {{window_size.x / 2 + shift.x, 0}, sfWhite},
            {{window_size.x / 2 + shift.x, window_size.y}, sfWhite}
        };

        if (line[0].position.x > 0 && line[0].position.x < window_size.x)
            sfRenderWindow_drawPrimitives(window, line, 2, sfLines, NULL);


        if (line2[0].position.y > 0 && line2[0].position.y < window_size.y)
            sfRenderWindow_drawPrimitives(window, line2, 2, sfLines, NULL);

        // pts plotting
        for (uint32_t i = 0; i < n; ++i) {
            sfCircleShape *pts = sfCircleShape_create();
            sfVector2f pos = {
                xs[i] * ratio.x + window_size.x / 2 - 10 + shift.x,
                window_size.y - ys[i] * ratio.y - 10 - window_size.y / 2 + shift.y
            };
            if (pos.x <= -20 || pos.x >= window_size.x || pos.y <= -20 || pos.y >= window_size.y)
                continue;
            sfCircleShape_setPosition(pts, pos);
            sfCircleShape_setRadius(pts, 10);
            sfCircleShape_setFillColor(pts, sfRed);
            sfRenderWindow_drawCircleShape(window, pts, NULL);
            sfCircleShape_destroy(pts);
        }

        // end plotting
        sfRenderWindow_display(window);

    }
    // free
    sfRenderWindow_destroy(window);
    return 0;
}
