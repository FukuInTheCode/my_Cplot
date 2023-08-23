#pragma once
#define MYPLOTH

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

#define SCALE 2

typedef struct my_ui my_ui_t;
typedef struct my_plot my_plot_t;

typedef struct my_fig {
    sfRenderWindow *window;
    char *title;
    sfEvent *event;
    my_ui_t *ui;
    my_plot_t *plot;
} my_fig_t;

typedef struct my_ui {
    sfColor background;
    sfColor point;
    double point_radius;
} my_ui_t;

typedef struct my_plot {
    size_t num;
    double *xs;
    double *ys;
    double margin_left;
    double margin_up;
    sfVector2f ratio;
    double axe1;
    double axe2;
} my_plot_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
void my_fig_calc_scale(my_fig_t *fig);
void my_plot_axes(my_fig_t *fig);
