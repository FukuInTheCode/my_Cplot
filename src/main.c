#include "../includes/my.h"

int main(void)
{

    // main

    uint32_t n = 8;
    uint32_t n2 = 3;

    double xs[] = { 0, 2, -1, 0, 1, 2, 3, 4 };
    double ys[] = { 0, 3, 2, 3, 1, 2, 3, 4 };
    double xs2[] = { 2, 3, 10 };
    double ys2[] = { -10, 3, 2 };

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

    my_plot_t plt = {
        .title = "test",
        .gs_n = 2,
        .gs = gs
    };

    my_plot_create(&plt, &plt_th);

    my_plot_show(&plt);
    // free
    sfRenderWindow_destroy(plt.window);
    return 0;
}
