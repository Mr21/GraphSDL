#include	<stdio.h>
#include	"graph.h"

int		main(void)
{
  Graph		graph;

  SDLazy_Init(860, 640, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE, "Graph2D");
  if (initGraph(&graph, SDLazy_GetScreen()))
    return fprintf(stderr, "Graph init failed :(\n");
  SDLazy_AddEvent(SDL_QUIT, eventQuit);
  SDLazy_AddEvent(SDL_KEYDOWN, eventKeyDown);
  SDLazy_AddEvent(SDL_MOUSEBUTTONDOWN, eventButtonDown);
  SDLazy_AddEvent(SDL_MOUSEBUTTONUP, eventButtonUp);
  SDLazy_AddEvent(SDL_MOUSEMOTION, eventMouseMotion);
  SDLazy_Loop(&graph, NULL, drawGraph);
  return EXIT_SUCCESS;
}
