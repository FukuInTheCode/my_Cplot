#pragma once
#define MY_PLOT_H

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

typedef struct {
    size_t data_num;

    sfVector2f max_values;
    sfVector2f min_values;

    sfVector2f interval;
    sfVector2f ratio;
    sfVector2f shift;
    sfVector2i last_shift;

    sfVector2f *points;

    sfBool is_dragged;
} my_graph_t;

typedef struct {
    double radius;
    sfColor bg;
    sfColor pt;
    sfColor axis;
} my_theme_t;

typedef struct {
    sfRenderWindow *window;
    sfEvent *event;
    my_theme_t *theme;
    my_graph_t *graph;
} my_plot_t;

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt);
void my_plot_show(my_plot_t *plt);
void my_plot_handle_event(my_plot_t *plt);
void my_plot_handle_mouse(my_plot_t *plt);
void my_plot_points(my_plot_t *plt);
void my_plot_axis(my_plot_t *plt);
