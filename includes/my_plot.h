#pragma once
#define MYPLOTH

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"

typedef struct my_fig {
    sfWindow *window;
    sfEvent *event;
} my_fig_t;
