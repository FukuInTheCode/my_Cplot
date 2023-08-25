#pragma once
#define MY_PLOT_H

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
    sfVector2i mouse_vec_save;
    sfVector2i shift_save;
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
    sfVector2f shift;
    sfVector2f ratio;
    sfVector2f axis;
    double min_x;
    double max_x;
    double min_y;
    double max_y;
} my_plot_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
void my_fig_calc_scale(my_fig_t *fig);
void my_fig_handle_event(my_fig_t *fig);

void my_plot(my_fig_t *fig);
void my_plot_axes(my_fig_t *fig);
void my_plot_handle_mouse(my_fig_t *fig);
void my_plot_point(my_fig_t *fig);