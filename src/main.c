#include "../includes/my.h"

typedef double (*MathFunction)(double);

static void generateArrays(int n, double x[], double y[], double start, double end, MathFunction func) {
    if (n <= 0 || start >= end) {
        printf("Error: Invalid parameters.\n");
        return;
    }

    double increment = (end - start) / (n - 1);
    for (int i = 0; i < n; i++) {
        x[i] = start + i * increment;
        y[i] = func(x[i]);
    }
}

static double fun(double x) {
    return x * x;
}

int main(void)
{
    my_colors_t colors = {.background = sfBlack};
    size_t n = 100;
    double x[n];
    double y[n];
    generateArrays(n, x, y, 0, 100, fun);

    my_plot_t plot = {.xs = x, .ys = y, .num = n};
    char *title = "test";
    sfEvent event;
    my_fig_t fig1 = {.title = title, .colors = &colors, .event = &event, .plot = &plot};

    my_fig_create(&fig1);
    my_fig_show(&fig1);

    return 0;
}
