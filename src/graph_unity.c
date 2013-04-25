#include	"graph.h"

int		graph_XtoPixel(double x)
{
  Graph*	g = SDLazy_GetData();

  return g->ori[X] + x * (g->unit_dist[X] / g->unit[X]);
}

int		graph_YtoPixel(double y)
{
  Graph*	g = SDLazy_GetData();

  return g->ori[Y] + y * (g->unit_dist[Y] / -g->unit[Y]);
}
