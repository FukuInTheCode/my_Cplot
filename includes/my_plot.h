#pragma once
#define MYPLOTH

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"

typedef struct my_colors my_colors_t;

typedef struct my_fig {
    sfWindow *window;
    sfEvent *event;
    my_colors_t *colors;
} my_fig_t;

typedef struct my_colors {
    sfColor background;
} my_colors_t;
