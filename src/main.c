#include "../includes/my.h"

int main(void)
{

    // main

    uint32_t n = 8;
    uint32_t n2 = 3;

    double xs[] = { 0, 2, -1, 0, 1, 2, 3, 4 };
    double ys[] = { 0, 3, 2, 3, 1, 2, 3, 4 };
    double xs2[] = { 2, 3, 4 };
    double ys2[] = { 0, 3, 2 };

    my_theme_t g2_th = {
        .point = sfYellow,
        .radius = 7
    };

    my_graph_t g2 = {
        .xs = xs2,
        .ys = ys2,
        .pts_n = n2,
        .th = &g2_th
    };
    my_theme_t g1_th = {
        .point = sfRed,
        .radius = 10
    };

    my_graph_t g1 = {
        .xs = xs,
        .ys = ys,
        .pts_n = n,
        .th = &g1_th
    };

    my_graph_t *gs[] = {
        &g1,
        &g2
    };

    my_theme_t plt_th = {
        .bg = sfBlack,
        .axis = sfWhite
    };

    sfEvent event;
    my_plot_t plt = {
        .title = "test",
        .event = &event,
        .th = &plt_th,
        .shift.x = 0,
        .shift.y = 0,
        .mouse_save.x = 0,
        .mouse_save.y = 0,
        .zoom.x = 0,
        .zoom.y = 0,
        .gs_n = 2,
        .gs = gs
    };

    // create window
    sfVideoMode mode = {1000, 1000, 32};
    plt.window = sfRenderWindow_create(mode, plt.title, sfDefaultStyle, NULL);

    // calc ratio
    sfVector2u window_size = sfRenderWindow_getSize(plt.window);

    plt.ratio.x = (window_size.x - 10) / (my_max(xs, n) - my_min(xs, n) + 0.1) / 2;
    plt.ratio.y = (window_size.y - 10) / (my_max(ys, n) - my_min(ys, n) + 0.1) / 2;

    // show
    while (sfRenderWindow_isOpen(plt.window)) {
        // event handling
        while (sfRenderWindow_pollEvent(plt.window, plt.event)) {
            if (plt.event->type == sfEvtClosed) {
                sfRenderWindow_close(plt.window);
            }
        }

        // plotting

        sfRenderWindow_clear(plt.window, plt.th->bg);

        // mouse handling
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (plt.is_pressed) {
                sfVector2i tmp = sfMouse_getPosition(NULL);
                plt.shift.x += tmp.x - plt.mouse_save.x;
                plt.shift.y += tmp.y - plt.mouse_save.y;
                plt.mouse_save = tmp;
            } else {
                plt.mouse_save = sfMouse_getPosition(NULL);
                plt.is_pressed = true;
            }
        } else if (plt.is_pressed)
            plt.is_pressed = false;

        // zoom handling
        if (sfKeyboard_isKeyPressed(sfKeyA)) {
            plt.zoom.x += 1;
            plt.zoom.y += 1;
        } else if (sfKeyboard_isKeyPressed(sfKeyZ)) {
            plt.zoom.x = my_max_between(plt.zoom.x - 1, -plt.ratio.x);
            plt.zoom.y = my_max_between(plt.zoom.y - 1, -plt.ratio.y);
        }

        // keyboard moving handling
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                plt.shift.x -= 10;
            else
                plt.shift.x -= 1;
        } else if (sfKeyboard_isKeyPressed(sfKeyRight))
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                plt.shift.x += 10;
            else
                plt.shift.x += 1;

        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                plt.shift.y -= 10;
            else
                plt.shift.y -= 1;
        } else if (sfKeyboard_isKeyPressed(sfKeyDown))
            if (sfKeyboard_isKeyPressed(sfKeyLControl))
                plt.shift.y += 10;
            else
                plt.shift.y += 1;

        if (sfKeyboard_isKeyPressed(sfKeyO)) {
            plt.shift.x = 0;
            plt.shift.y = 0;
            plt.zoom.x = 0;
            plt.zoom.y = 0;
        }

        // axis plotting
        sfVertex line2[] = {
            {{0, window_size.y / 2 + plt.shift.y}, plt.th->axis},
            {{window_size.x, window_size.y / 2 + plt.shift.y}, plt.th->axis}
        };

        sfVertex line[] = {
            {{window_size.x / 2 + plt.shift.x, 0}, plt.th->axis},
            {{window_size.x / 2 + plt.shift.x, window_size.y}, plt.th->axis}
        };

        if (line[0].position.x > 0 && line[0].position.x < window_size.x)
            sfRenderWindow_drawPrimitives(plt.window, line, 2, sfLines, NULL);


        if (line2[0].position.y > 0 && line2[0].position.y < window_size.y)
            sfRenderWindow_drawPrimitives(plt.window, line2, 2, sfLines, NULL);

        // pts plotting
        for (uint32_t j = 0; j < plt.gs_n; ++j) {
            for (uint32_t i = 0; i < plt.gs[j]->pts_n; ++i) {
                sfCircleShape *pts = sfCircleShape_create();
                sfVector2f pos = {
                    plt.gs[j]->xs[i] * (plt.ratio.x + plt.zoom.x) + window_size.x / 2 - 10 + plt.shift.x,
                    window_size.y - plt.gs[j]->ys[i] * (plt.ratio.y + plt.zoom.y) - 10 - window_size.y / 2 + plt.shift.y
                };
                if (pos.x <= -20 || pos.x >= window_size.x || pos.y <= -20 || pos.y >= window_size.y)
                    continue;
                sfCircleShape_setPosition(pts, pos);
                sfCircleShape_setRadius(pts, plt.gs[j]->th->radius);
                sfCircleShape_setFillColor(pts, plt.gs[j]->th->point);
                sfRenderWindow_drawCircleShape(plt.window, pts, NULL);
                sfCircleShape_destroy(pts);
            }
        }

        // end plotting
        sfRenderWindow_display(plt.window);

    }
    // free
    sfRenderWindow_destroy(plt.window);
    return 0;
}
