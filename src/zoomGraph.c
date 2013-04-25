#include			"graph.h"

#define				ZOOM_INC		10
#define				MIN_DIST		160

static int			_zoom(Graph *g, int i)
{
  if (g->unit_dist[i] < MIN_DIST / 2)
    {
      g->unit_dist[i] = MIN_DIST;
      g->unit[i] *= 2;
    }
  else if (g->unit_dist[i] > MIN_DIST * 2)
    {
      g->unit_dist[i] = MIN_DIST;
      g->unit[i] /= 2;
    }
  else
    return 1;
  return 0;
}

static void			_calc_zoom(Graph *g, int zoom)
{
  double			z = ZOOM_INC * zoom;

  g->unit_dist[X] += z;
  g->unit_dist[Y] += z;
  if (_zoom(g, X))
    g->ori[X] -= z * g->x / g->unit[X];
  if (_zoom(g, Y))
    g->ori[Y] += z * g->y / g->unit[Y];
}

void				graph_zoomIn (Graph *g){_calc_zoom(g, +1);}
void				graph_zoomOut(Graph *g){_calc_zoom(g, -1);}
