#include "../includes/my.h"

double exampleFunction(double x) {
    return x;
}
double exampleFunction2(double x) {
    return x * x;
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
    sfVector2f c_pts[num];
    sfVector2f points2[num];
    sfVector2f c_pts2[num];

    generatePoints(points, num, exampleFunction, start, end);
    generatePoints(points2, num, exampleFunction, start, end);

    // for (int i = 0; i < num; i++) {
    //     printf("{%.2f, %.2f},\n", points[i].x, points[i].y);
    // }


    printf("--------------\n");

    // double undef[] = { 1 };

    // my_func_t f = {
    //     .f = exampleFunction,
    //     .left_type = inf,
    //     .right_type = inf,
    //     .n_undef = 1,
    //     .undefined = undef
    // };

    my_theme_t th_plt = {
        .type = plot_th,
        .plot.bg = sfBlack,
        .plot.axis = sfWhite
    };
    my_theme_t th_g1 = {
        .type = graph_th,
        .graph.radius = 10,
        .graph.pt = sfRed
    };
    my_theme_t th_g2 = {
        .type = graph_th,
        .graph.radius = 10,
        .graph.pt = sfYellow
    };

    my_graph_t g = {
        .points = points,
        .computed_pts = c_pts,
        .data_num = num,
        .type = static_pts,
        .theme = &th_g1
    };

    my_graph_t g = {
        .points = points,
        .computed_pts = c_pts,
        .data_num = num,
        .type = static_pts,
        .theme = &th_g2
    };

    my_graph_t *g_arr[] = {
        &g,
        &g2
    };

    my_plot_t plt = {
        .graph = g_arr,
        .graph_n = 1,
        .theme = &th_plt
    };
    sfVideoMode mode = {1000, 1000, 32};
    char *title = "Hello World";
    sfEvent evt;
    my_plot_create(&plt, title, &mode, &evt);

    my_plot_show(&plt);

    // sfRenderWindow_destroy(plt.window);

    return 0;
}
