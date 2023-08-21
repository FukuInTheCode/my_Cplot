#include "../includes/my.h"

int main(void)
{
    my_colors_t colors = {.background = sfBlack};
    char *title = "test";
    sfEvent event;
    my_fig_t fig1 = {.title = title, .colors = &colors, .event = &event};

    my_fig_create(&fig1);
    my_fig_show(&fig1);

    return 0;
}
