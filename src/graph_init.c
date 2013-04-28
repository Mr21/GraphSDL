#include		<string.h>
#include		"graph.h"

int			graph_init(Graph* g, void (*userCore)(Graph*), void (*userRender)(Graph const*), SDL_Surface* srf)
{
  SDLazy_SetData(g);
  if (TTF_Init() == -1)
    return fprintf(stderr, "TTF_Init failed: %s\n", TTF_GetError());
  memset(g, 0, sizeof(Graph));
  if (!(g->font = TTF_OpenFont("font/saxmono.ttf", 14)))
    return fprintf(stderr, "TTF_OpenFont failed: %s\n", TTF_GetError());
  g->userCore = userCore;
  g->userRender = userRender;
  g->srf = srf != NULL ? srf : SDLazy_GetScreen();
  g->ori[X] = g->srf->w / 2;
  g->ori[Y] = g->srf->h / 2;
  g->unit[X] = 1.0;
  g->unit[Y] = 1.0;
  g->unit_dist[X] = 150;
  g->unit_dist[Y] = 150;
  g->col[0] = SDL_MapRGB(g->srf->format, 96, 96, 96);
  g->col[1] = SDL_MapRGB(g->srf->format, 48, 48, 48);
  g->col[2] = SDL_MapRGB(g->srf->format, 24, 24, 24);
  g->col[3] = SDL_MapRGB(g->srf->format, 192, 192, 192);
  g->col[4] = SDL_MapRGB(g->srf->format, 255, 100, 100);
  g->col[5] = SDL_MapRGB(g->srf->format, 100, 255, 100);
  graph_calcScreenCoord(g);
  return 0;
}
