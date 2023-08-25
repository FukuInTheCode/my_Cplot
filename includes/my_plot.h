#pragma once
#define MY_PLOT_H

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

#define SCALE 2

typedef struct my_ui my_ui_t;
typedef struct my_plot my_plot_t;

typedef double (*math_function)(double);

typedef enum {
    inf,
    minus_inf,
    integer
} math_func_limit;

typedef enum {
    points,
    function_pts
} plot_type_t;

typedef struct my_fig {
    sfRenderWindow *window;
    char *title;
    sfEvent *event;
    my_ui_t *ui;
    my_plot_t *plot;
    uint8_t is_moving;
    sfVector2i mouse_vec_save;
    sfVector2i shift_save;
} my_fig_t;

typedef struct my_ui {
    sfColor background;
    sfColor point;
    double point_radius;
} my_ui_t;

typedef struct my_plot {
    plot_type_t type;

    size_t num;
    double *xs;
    double *ys;
    double min_x;
    double max_x;
    double min_y;
    double max_y;

    math_function func;
    math_func_limit left;
    math_func_limit right;

    sfVector2f shift;
    sfVector2f ratio;
    sfVector2f axis;
} my_plot_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
void my_fig_calc_scale(my_fig_t *fig);
void my_fig_handle_event(my_fig_t *fig);

void my_plot(my_fig_t *fig);
void my_plot_axes(my_fig_t *fig);
void my_plot_handle_mouse(my_fig_t *fig);
void my_plot_point(my_fig_t *fig);
void my_plot_function(my_fig_t *fig);