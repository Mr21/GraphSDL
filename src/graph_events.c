#include		"graph.h"

void			graph_eventQuit(SDL_Event* e)
{
  (void)e;
  SDLazy_Quit(0);
}

void			graph_eventResize(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  (void)e;
  graph_calcScreenCoord(g);
}

void			graph_eventKeyDown(SDL_Event* e)
{
  switch (e->key.keysym.sym)
    {
    case SDLK_ESCAPE: SDLazy_Quit(0);
    default: break;
    }
}

void			graph_eventButtonDown(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  switch (e->button.button)
    {
    case SDL_BUTTON_WHEELDOWN:	graph_zoomOut(g);	break;
    case SDL_BUTTON_WHEELUP:	graph_zoomIn(g);	break;
    case SDL_BUTTON_LEFT:	graph_dragOn(g);	break;
    }
}

void			graph_eventButtonUp(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  if (e->button.button == SDL_BUTTON_LEFT)
    graph_dragOff(g);
}

void			graph_eventMouseMotion(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  if (graph_isDragging(g))
    {
      g->ori[X] += e->motion.xrel;
      g->ori[Y] += e->motion.yrel;
      g->drag_smooth[X] = abs(e->motion.xrel) > 2 ? e->motion.xrel : 0;
      g->drag_smooth[Y] = abs(e->motion.yrel) > 2 ? e->motion.yrel : 0;
      graph_calcScreenCoord(g);
    }
  g->x = (e->motion.x - g->ori[X]) / g->unit_dist[X] * +g->unit[X];
  g->y = (e->motion.y - g->ori[Y]) / g->unit_dist[Y] * -g->unit[Y];
}
