#pragma once
#define MY_PLOT_H

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

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
} my_plot_t;

void my_plot_create(my_plot_t *plt, char *title, sfVideoMode *md, sfEvent *evt);
