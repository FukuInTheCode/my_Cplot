#include "../../includes/my.h"

void my_plot_append(my_plot_t *plt, my_graph_t *g)
{
    my_graph_t **tmp = plt->gs;
    plt->gs = malloc((plt->gs_n + 1) * sizeof(my_graph_t *));
    if (plt->gs == NULL) {
        fprintf(stderr, "Memory allocation failed!");
        exit(1);
    }
    for (uint32_t i = 0; i < plt->gs_n; ++i)
        plt->gs[i] = tmp[i];

    plt->gs[(plt->gs_n)++] = g;

    if (plt->gs_n > 1)
        free(temp);
}
