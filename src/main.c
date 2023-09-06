#include "../includes/my.h"

typedef struct {
    int a;
    int b;
} my_p_t;

double sq(double x)
{
    return x * x;
}

double sq2(double x, my_p_t *p)
{
    return (x + p->a) * (x + p->a) + p->b;
}

int main(void)
{

    // main

    uint32_t n = 8;
    uint32_t n2 = 100;

    double xs[] = { 0, 2, -1, 0, 1, 2, 3, 4 };
    double ys[] = { 0, 3, 2, 3, 1, 2, 3, 4 };
    double xs2[n2];
    double ys2[n2];
    double xs3[n2];
    double ys3[n2];

    my_p_t ps = {.a = 1,  .b = 2};

    my_theme_t g2_th = {
        .point = sfYellow,
        .radius = 7
    };

    my_graph_t g2 = {
        .type = function,
        .xs = xs2,
        .ys = ys2,
        .pts_n = 0,
        .max_pts_n = n2,
        .th = &g2_th,
        .f = sq
    };
    my_theme_t g3_th = {
        .point = sfBlue,
        .radius = 13
    };

    my_graph_t g3 = {
        .type = function2,
        .xs = xs3,
        .ys = ys3,
        .pts_n = 0,
        .max_pts_n = n2,
        .th = &g3_th,
        .f2 = sq2,
        .params = (void *)(&ps)
    };
    my_theme_t g1_th = {
        .point = sfRed,
        .radius = 10
    };

    my_graph_t g1 = {
        .type = points,
        .xs = xs,
        .ys = ys,
        .pts_n = n,
        .th = &g1_th
    };

    my_theme_t plt_th = {
        .bg = sfBlack,
        .axis = sfWhite
    };

    my_plot_t plt = {
        .title = "test",
        .gs_n = 0
    };

    my_plot_create(&plt, &plt_th);

    my_plot_append(&plt, &g1);
    printf("Hello\n");

    my_plot_show(&plt);

    my_plot_free(&plt);
    return 0;
}
