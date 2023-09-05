#include "../../includes/my.h"

void my_plot_pts(my_plot_t *plt, my_graph_t *g)
{
    sfVector2u window_size = sfRenderWindow_getSize(plt->window);

    for (uint32_t i = 0; i < g->pts_n; ++i) {
        sfVector2f pos = {
            g->xs[i] * (plt->ratio.x + plt->zoom.x) + window_size.x / 2 - 10 + plt->shift.x,
            window_size.y - g->ys[i] * (plt->ratio.y + plt->zoom.y) - 10 - window_size.y / 2 + plt->shift.y
        };
        if (pos.x <= -20 || pos.x >= window_size.x || pos.y <= -20 || pos.y >= window_size.y)
            continue;

        sfCircleShape *pts = sfCircleShape_create();
        sfCircleShape_setPosition(pts, pos);
        sfCircleShape_setRadius(pts, g->th->radius);
        sfCircleShape_setFillColor(pts, g->th->point);
        sfRenderWindow_drawCircleShape(plt->window, pts, NULL);
        sfCircleShape_destroy(pts);
    }

}