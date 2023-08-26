#pragma once
#define MY_PLOT_H

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

typedef enum {
    pts,
    axis
} my_obj_type_t;

typedef enum {
    static_pts,
    dynamic_pts,
    static_func,
    dynamic_func
} my_graph_type_t;

typedef struct {
    my_graph_type_t type;

    sfVector2f max_values;
    sfVector2f min_values;

    sfVector2f ratio;
    sfVector2f shift;
    sfVector2i last_shift;
    size_t data_num;
    struct {
        size_t max_pts;
        my_func_t func;
    } st_func;
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

static inline __attribute__((always_inline)) void compute_pts(my_plot_t *plt)
{
    sfVector2u tmp_vec = sfRenderWindow_getSize(plt->window);
    for (size_t i = 0; i < plt->graph->data_num; ++i) {
        plt->graph->points[i].y *= plt->graph->ratio.y;
        plt->graph->points[i].x *= plt->graph->ratio.x;
        plt->graph->points[i].y = (tmp_vec.y - plt->theme->radius*2) -\
                                    plt->graph->points[i].y;
        plt->graph->points[i].x += tmp_vec.x / 2.f;
        plt->graph->points[i].y -= tmp_vec.y / 2.f;
    }
}

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt);
void my_plot_show(my_plot_t *plt);
void my_plot_handle_event(my_plot_t *plt);
void my_plot_handle_mouse(my_plot_t *plt);
void my_plot_points(my_plot_t *plt);
void my_plot_axis(my_plot_t *plt);
sfBool my_plot_is_onscreen(my_plot_t *plt, sfVector2f coords,\
                            my_obj_type_t type);
void my_plot_func(my_plot_t *plt);
