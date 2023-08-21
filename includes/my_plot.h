#pragma once
#define MYPLOTH

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"

#define SCALE 2

typedef struct my_colors my_colors_t;

typedef struct my_fig {
    sfRenderWindow *window;
    char *title;
    sfEvent *event;
    my_colors_t *colors;
} my_fig_t;

typedef struct my_colors {
    sfColor background;
} my_colors_t;

void my_fig_create(my_fig_t *fig);
void my_fig_show(my_fig_t *fig);
