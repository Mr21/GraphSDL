#include	"graph.h"

void		graph_core(void)
{
  Graph*	g = SDLazy_GetData();

  if (!graph_isDragging(g))
    {
      g->ori[X] += (g->drag_smooth[X] /= DRAG_SMOOTH_SPEED);
      g->ori[Y] += (g->drag_smooth[Y] /= DRAG_SMOOTH_SPEED);
      graph_calcScreenCoord(g);
    }
  g->userCore(g);
}
