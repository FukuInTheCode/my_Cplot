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
    double start = -10;
    double end = 10;
    size_t num = 21;

    sfVector2f points[num];

    generatePoints(points, num, exampleFunction, start, end);

    for (int i = 0; i < num; i++) {
        printf("{%.2f, %.2f},\n", points[i].x, points[i].y);
    }

    my_func_t f = {
        .f = exampleFunction
    };

    my_graph_t g = {
        .points = points,
        .data_num = num,
        .st_func.max_pts = 21,
        .st_func.func = f,
        .type = static_func
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

    my_plot_show(&plt);

    sfRenderWindow_destroy(plt.window);

    return 0;
}
