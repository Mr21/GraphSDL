#include		"graph.h"

void			graph_drawDot(Graph const* g, double x, double y, Uint32 col)
{
  int			_x, _y;
  int			i;
  int			sz = 4;

  _x = g->ori[X] + x * (g->unit_dist[X] / g->unit[X]);
  _y = g->ori[Y] + y * (g->unit_dist[Y] / -g->unit[Y]);
  for (i = -sz; i <= sz; ++i)
    SDLazy_SetPix_Secure(g->srf, _x + i, _y, col);
  for (i = -sz; i <= sz; ++i)
    SDLazy_SetPix_Secure(g->srf, _x, _y + i, col);
}
