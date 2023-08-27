#include "../../includes/my.h"

void my_plot_points(my_plot_t *plt)
{
    for (size_t i = 0; i < plt->graph->data_num; ++i) {
        sfVector2f tmp_pts = plt->graph->points[i];
        tmp_pts.x += plt->graph->shift.x - plt->graph->theme->radius;
        tmp_pts.y += plt->graph->shift.y + plt->graph->theme->radius;
        if (!my_plot_is_onscreen(plt, tmp_pts, pts))
            continue;
        sfCircleShape *current_pts = sfCircleShape_create();
        sfCircleShape_setFillColor(current_pts, plt->graph->theme->pt);
        sfCircleShape_setRadius(current_pts, plt->graph->theme->radius);
        sfCircleShape_setPosition(current_pts, tmp_pts);
        sfRenderWindow_drawCircleShape(plt->window, current_pts, NULL);
        sfCircleShape_destroy(current_pts);
    }
}
