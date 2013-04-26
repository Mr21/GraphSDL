#include	"graph.h"

void		graph_calcScreenCoord(Graph* g)
{
  g->scrCoordA[X] = graph_XtoDouble(0);
  g->scrCoordA[Y] = graph_YtoDouble(0);
  g->scrCoordB[X] = graph_XtoDouble(g->srf->w);
  g->scrCoordB[Y] = graph_YtoDouble(g->srf->h);
}
