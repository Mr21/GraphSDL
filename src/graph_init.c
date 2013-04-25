#include		<string.h>
#include		"graph.h"

int			graph_init(Graph* g, SDL_Surface* srf)
{
  if (TTF_Init() == -1)
    return fprintf(stderr, "TTF_Init failed: %s\n", TTF_GetError());
  memset(g, 0, sizeof(Graph));
  if (!(g->font = TTF_OpenFont("font/square.ttf", 10)))
    return fprintf(stderr, "TTF_OpenFont failed: %s\n", TTF_GetError());
  g->srf = srf;
  g->ori[X] = srf->w / 2;
  g->ori[Y] = srf->h / 2;
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
  return 0;
}
