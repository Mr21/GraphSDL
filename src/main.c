#include	<stdio.h>
#include	"graph.h"

void		calcMyStuff(Graph* g)
{
  (void)g;
}

void		drawMyStuff(Graph const* g)
{
  graph_drawCircle(g,
		   +0.5, +0.5,
		   0.5,
		   0x0000ff);
  graph_drawLine(g,
                 -3.1415, -2.0,
                 +3.1415, +2.0,
                 0xff0000);
  graph_drawLine(g,
                 -2.00, 1.0,
                 +3.00, 3.0,
                 0x00ff00);
}

int		main(void)
{
  Graph		graph;

  SDLazy_Init(860, 640, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE, "Graph2D");
  if (graph_init(&graph, calcMyStuff, drawMyStuff, NULL))
    return fprintf(stderr, "Graph init failed :(\n");
  /* Set events */
  SDLazy_AddEvent(SDL_QUIT,		graph_eventQuit);
  SDLazy_AddEvent(SDL_VIDEORESIZE,	graph_eventResize);
  SDLazy_AddEvent(SDL_KEYDOWN,		graph_eventKeyDown);
  SDLazy_AddEvent(SDL_MOUSEBUTTONDOWN,	graph_eventButtonDown);
  SDLazy_AddEvent(SDL_MOUSEBUTTONUP,	graph_eventButtonUp);
  SDLazy_AddEvent(SDL_MOUSEMOTION,	graph_eventMouseMotion);
  /* Infinite loop */
  SDLazy_Loop(&graph, graph_core, graph_draw);
  return EXIT_SUCCESS;
}
