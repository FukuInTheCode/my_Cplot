#include "../includes/my.h"

double exampleFunction(double x) {
    return x;
}

void generatePoints(sfVector2f points[], int num, double (*func)(double), double start, double end) {
    double step = (end - start) / (num - 1);
    for (int i = 0; i < num; i++) {
        double x = start + i * step;
        points[i].x = x;
        points[i].y = func(x);
    }
}

int main(void)
{
    double start = -1.0;
    double end = 3.0;
    int num = 20;

    sfVector2f points[num];

    generatePoints(points, num, exampleFunction, start, end);

    for (int i = 0; i < num; i++) {
        printf("{%.2f, %.2f},\n", points[i].x, points[i].y);
    }

    my_graph_t g = {
        .points = points,
        .data_num = num
    };


    my_theme_t th = {
        10,
        sfBlack,
        sfRed,
        sfWhite
    };

    my_plot_t plt = {.theme = &th, .graph = &g};
    sfVideoMode mode = {1000, 1000, 32};
    char *title = "Hello World";
    sfEvent evt;
    my_plot_create(&plt, title, &mode, &evt);

    for (int i = 0; i < plt.graph->data_num; i++) {
        printf("{%.2f, %.2f},\n", plt.graph->points[i].x, plt.graph->points[i].y);
    }
#if 0
    // sfVector2u tmp_vec = sfRenderWindow_getSize(plt.window);

    // for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
    //     if (points[i].x > max_values.x) max_values.x = points[i].x;
    //     if (points[i].y > max_values.y) max_values.y = points[i].y;
    //     if (points[i].x < min_values.x) min_values.x = points[i].x;
    //     if (points[i].y < min_values.y) min_values.y = points[i].y;
    // }

    // sfVector2f interval = {
    //     max_values.x - min_values.x,
    //     max_values.y - min_values.y,
    // };
    // sfVector2f ratio = {
    //     (tmp_vec.x - plt.theme->radius*2) / interval.x,
    //     (tmp_vec.y - plt.theme->radius*2) / interval.y
    // };
    // for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
    //     points[i].x *= ratio.x;
    //     points[i].y *= ratio.y;
    //     points[i].y = (tmp_vec.y - plt.theme->radius*2) - points[i].y;
    //     points[i].x += tmp_vec.x / 2.f;
    //     points[i].y -= tmp_vec.y / 2.f;
    // }

    // sfBool is_graph_drag = sfFalse;

    // sfVector2i shift = {0, 0};

    // sfVector2i last_shift = {0, 0};

    while (sfRenderWindow_isOpen(plt.window)) {
        while (sfRenderWindow_pollEvent(plt.window, plt.event)) {
            if (plt.event->type == sfEvtClosed)
                sfRenderWindow_close(plt.window);
        }

        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (!is_graph_drag) {
                is_graph_drag = sfTrue;
                last_shift = sfMouse_getPosition(plt.window);
            }
            else {
                sfVector2i mouse_vec = sfMouse_getPosition(plt.window);
                shift.x += mouse_vec.x - last_shift.x;
                shift.y += mouse_vec.y - last_shift.y;
                last_shift = mouse_vec;
            }
        } else
            is_graph_drag = sfFalse;

        sfRenderWindow_clear(plt.window, plt.theme->bg);
        for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
            sfCircleShape *current_pts = sfCircleShape_create();
            sfCircleShape_setFillColor(current_pts, plt.theme->pt);
            sfCircleShape_setRadius(current_pts, plt.theme->radius);
            sfVector2f tmp_pts = points[i];
            tmp_pts.x += shift.x;
            tmp_pts.y += shift.y;
            sfCircleShape_setPosition(current_pts, tmp_pts);
            sfRenderWindow_drawCircleShape(plt.window, current_pts, NULL);
            sfCircleShape_destroy(current_pts);
        }
        sfVertex line[] = {
            {{0, shift.y + tmp_vec.y / 2}, plt.theme->axis},
            {{tmp_vec.x, shift.y + tmp_vec.y / 2}, plt.theme->axis}
        };

        sfRenderWindow_drawPrimitives(plt.window, line, 2, sfLines, NULL);
        sfVertex line2[] = {
            {{tmp_vec.x / 2 + shift.x, 0}, plt.theme->axis},
            {{tmp_vec.x / 2 + shift.x, tmp_vec.y}, plt.theme->axis}
        };

        sfRenderWindow_drawPrimitives(plt.window, line2, 2, sfLines, NULL);
        sfRenderWindow_display(plt.window);
    }

    sfRenderWindow_destroy(plt.window);

#endif
    return 0;
}
