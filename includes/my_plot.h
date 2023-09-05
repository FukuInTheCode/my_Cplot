#ifndef MY_CPLOT_H
#define MY_CPLOT_H

#include "SFML/Graphics.h"

typedef struct {
    double *xs;
    double *ys;
    uint32_t pts_n;
    uint32_t max_pts_n;
} my_graph_t;

typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
    char *title;
} my_plot_t;

#endif