#include	"graph.h"

void		graph_dragOn (Graph* g){g->dragging = 1;}
void		graph_dragOff(Graph* g){g->dragging = 0;}
int		graph_isDragging(Graph const* g){return g->dragging;}
