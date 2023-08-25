#pragma once
#define MY_PLOT_H

#include "../includes/SFML/Graphics.h"
#include "../includes/SFML/Window.h"
#include "my_math.h"

typedef struct {
    sfRenderWindow *window;
    sfEvent *event;
} my_plot_t;

void hello2(void);
