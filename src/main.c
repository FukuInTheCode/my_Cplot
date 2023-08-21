#include "../includes/my.h"

int main(void)
{
    my_colors_t colors = {.background = sfBlack};
    double x[] = {1, 2, 3};
    double y[] = {3, 2, 1};
    my_plot_t plot = {.xs = x, .ys = y, .num = 3};

    my_plot_init(&plot);

    char *title = "test";
    sfEvent event;
    my_fig_t fig1 = {.title = title, .colors = &colors, .event = &event};

    my_fig_create(&fig1);
    my_fig_show(&fig1);

    return 0;
}
