#include	"graph.h"

void		graph_calcScreenDim(Graph* g)
{
  g->scrDim[W] = graph_XtoDouble(g->srf->w) - g->scrCoord[X];
  g->scrDim[H] = graph_YtoDouble(g->srf->h) - g->scrCoord[Y];
}
