#include		"graph.h"

int			eventQuit(SDL_Event* e)
{
  (void)e;
  SDLazy_Quit(0);
  return 0;
}

int			eventKeyDown(SDL_Event* e)
{
  switch (e->key.keysym.sym)
    {
    case SDLK_ESCAPE: SDLazy_Quit(0);
    default: break;
    }
  return 0;
}

int			eventButtonDown(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  switch (e->button.button)
    {
    case SDL_BUTTON_WHEELDOWN:	zoomGraph(g, -1);	break;
    case SDL_BUTTON_WHEELUP:	zoomGraph(g, 1);	break;
    case SDL_BUTTON_LEFT:	g->dragging = 1;	break;
    }
  return 0;
}

int			eventButtonUp(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  if (e->button.button == SDL_BUTTON_LEFT)
    g->dragging = 0;
  return 0;
}

int			eventMouseMotion(SDL_Event* e)
{
  Graph*		g = SDLazy_GetData();

  if (g->dragging)
    {
      g->ori[X] += (g->drag_smooth[X] = e->motion.xrel);
      g->ori[Y] += (g->drag_smooth[Y] = e->motion.yrel);
    }
  g->x = (e->motion.x - g->ori[X]) / g->unit_dist[X] * g->unit[X];
  g->y = (e->motion.y - g->ori[Y]) / g->unit_dist[Y] * -g->unit[Y];
  return 0;
}
