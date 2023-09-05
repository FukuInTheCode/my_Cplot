#ifndef MY_CPLOT_H
#define MY_CPLOT_H

#include "SFML/Graphics.h"
#include "my_math.h"

typedef union {
    struct {
        sfColor bg;
        sfColor axis;
    };
    struct {
        sfColor point;
        uint32_t radius;
    };
} my_theme_t;

typedef struct {
    double *xs;
    double *ys;
    uint32_t pts_n;
    uint32_t max_pts_n;
    my_theme_t *th;
} my_graph_t;

typedef struct {
    sfRenderWindow *window;
    sfEvent *event;
    char *title;
    my_theme_t *th;
    uint32_t gs_n;
    my_graph_t **gs;
    sfVector2f ratio;
    sfVector2f shift;
    sfVector2f zoom;
    bool is_pressed;
    sfVector2i mouse_save;
} my_plot_t;

#endif