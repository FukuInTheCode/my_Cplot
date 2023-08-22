#pragma once
#define MYPLOTH

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

#define SCALE 2

typedef struct my_colors my_colors_t;
typedef struct my_plot my_plot_t;

typedef struct my_fig {
    sfRenderWindow *window;
    char *title;
    sfEvent *event;
    my_colors_t *colors;
    my_plot_t *plot;
} my_fig_t;

typedef struct my_colors {
    sfColor background;
} my_colors_t;

typedef struct my_plot {
    size_t num;
    double *xs;
    double *ys;
    double min_x;
    double min_y;
    sfVector2f ratio;
} my_plot_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
void my_plot_init(my_plot_t *plot);
void my_fig_plot(my_fig_t *fig);
