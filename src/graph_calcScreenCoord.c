#include	"graph.h"

void		graph_calcScreenCoord(Graph* g)
{
  g->scrCoord[X] = graph_XtoDouble(0);
  g->scrCoord[Y] = graph_YtoDouble(0);
}
