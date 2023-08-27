#include "../../includes/my.h"

void my_plot_points(my_plot_t *plt, my_graph_t *g)
{
    compute_pts(plt, g);
    size_t num = g->data_num;
    if (g->type == dynamic_pts && num > g->max_pts)
        num = g->max_pts;
    for (size_t i = 0; i < num; ++i) {
        sfVector2f tmp_pts = g->computed_pts[i];
        tmp_pts.x += plt->shift.x - g->theme->graph.radius;
        tmp_pts.y += plt->shift.y + g->theme->graph.radius;
        if (!my_plot_is_onscreen(plt, tmp_pts, pts, g))
            continue;
        sfCircleShape *current_pts = sfCircleShape_create();
        sfCircleShape_setFillColor(current_pts, g->theme->graph.pt);
        sfCircleShape_setRadius(current_pts, g->theme->graph.radius);
        sfCircleShape_setPosition(current_pts, tmp_pts);
        sfRenderWindow_drawCircleShape(plt->window, current_pts, NULL);
        sfCircleShape_destroy(current_pts);
    }
}
