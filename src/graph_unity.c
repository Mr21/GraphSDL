#include	"graph.h"

int		graph_scalePixel(double w)
{
  Graph*	g = SDLazy_GetData();

  return w * (g->unit_dist[X] / +g->unit[X]);
}

int		graph_XtoPixel(double x)
{
  Graph*	g = SDLazy_GetData();

  return g->ori[X] + x * (g->unit_dist[X] / +g->unit[X]);
}

int		graph_YtoPixel(double y)
{
  Graph*	g = SDLazy_GetData();

  return g->ori[Y] + y * (g->unit_dist[Y] / -g->unit[Y]);
}

double		graph_XtoDouble(int x)
{
  Graph*	g = SDLazy_GetData();

  return (x - g->ori[X]) / (g->unit_dist[X] / +g->unit[X]);
}

double		graph_YtoDouble(int y)
{
  Graph*	g = SDLazy_GetData();

  return (y - g->ori[Y]) / (g->unit_dist[Y] / -g->unit[Y]);
}
