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
    uint8_t is_moving;
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
    double hor_shift;
    double ver_shift;
    sfVector2f ratio;
    double axe1;
    double axe2;
    double min_x;
    double max_x;
    double min_y;
    double max_y;
} my_plot_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
void my_fig_calc_scale(my_fig_t *fig);
void my_plot_axes(my_fig_t *fig);
void my_fig_handle_event(my_fig_t *fig);
void my_plot_handle_mouse(my_fig_t *fig);