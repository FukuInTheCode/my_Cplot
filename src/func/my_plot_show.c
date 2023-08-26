#include "../../includes/my.h"

void my_plot_show(my_plot_t *plt)
{
    while (sfRenderWindow_isOpen(plt.window)) {

        my_plot_handle_event(plt);

        sfRenderWindow_clear(plt.window, plt.theme->bg);
        for (size_t i = 0; i < ARRAY_LENGTH(points); ++i) {
            sfCircleShape *current_pts = sfCircleShape_create();
            sfCircleShape_setFillColor(current_pts, plt.theme->pt);
            sfCircleShape_setRadius(current_pts, plt.theme->radius);
            sfVector2f tmp_pts = points[i];
            tmp_pts.x += shift.x;
            tmp_pts.y += shift.y;
            sfCircleShape_setPosition(current_pts, tmp_pts);
            sfRenderWindow_drawCircleShape(plt.window, current_pts, NULL);
            sfCircleShape_destroy(current_pts);
        }
        sfVertex line[] = {
            {{0, shift.y + tmp_vec.y / 2}, plt.theme->axis},
            {{tmp_vec.x, shift.y + tmp_vec.y / 2}, plt.theme->axis}
        };

        sfRenderWindow_drawPrimitives(plt.window, line, 2, sfLines, NULL);
        sfVertex line2[] = {
            {{tmp_vec.x / 2 + shift.x, 0}, plt.theme->axis},
            {{tmp_vec.x / 2 + shift.x, tmp_vec.y}, plt.theme->axis}
        };

        sfRenderWindow_drawPrimitives(plt.window, line2, 2, sfLines, NULL);
        sfRenderWindow_display(plt.window);
    }
}