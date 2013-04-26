#include	<stdio.h>
#include	"graph.h"

int		main(void)
{
  Graph		graph;

  SDLazy_Init(860, 640, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE, "Graph2D");
  if (graph_init(&graph, SDLazy_GetScreen()))
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
