#pragma once
#define MYPLOTH

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"

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
    int32_t *xs;
    int32_t *ys;
    uint32_t num;
    int32_t max_x;
    int32_t min_x;
    int32_t max_y;
    int32_t min_y;
} my_plot_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
