#include		"graph.h"

void			drawLineW(SDL_Surface *srf, int y, Uint32 px, e_border style)
{
  int			x;

  if (y >= 0 && y < srf->h)
    switch (style)
      {
      case SOLID:
	for (x = 0; x < srf->w; ++x)
	  SDLazy_SetPix(srf, x, y, px);
	break;
      case DOTTED:
	for (x = 0; x < srf->w; ++x)
	  if (x % 3 == 0)
	    SDLazy_SetPix(srf, x, y, px);
	break;
      case DASHED:
	for (x = 0; x < srf->w; ++x)
	  if (x % 8 > 4)
	    SDLazy_SetPix(srf, x, y, px);
	break;
      }
}

void			drawLineH(SDL_Surface *srf, int x, Uint32 px, e_border style)
{
  int			i;

  if (x >= 0 && x < srf->w)
    switch (style)
      {
      case SOLID:
        for (i = 0; i < srf->h; ++i)
          SDLazy_SetPix(srf, x, i, px);
        break;
      case DOTTED:
        for (i = 0; i < srf->h; ++i)
          if (i % 3 == 0)
            SDLazy_SetPix(srf, x, i, px);
        break;
      case DASHED:
        for (i = 0; i < srf->h; ++i)
          if (i % 8 > 4)
            SDLazy_SetPix(srf, x, i, px);
        break;
      }
}

static void		_case1(int x1, int y1, int x2, int y2, Uint32 col, SDL_Surface* srf)
{
  int			x, y;

  for (x = x1; x < x2; ++x)
    {
      y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
      SDLazy_SetPix_Secure(srf, x, y, col);
    }
}

static void		_case2(int x1, int y1, int x2, int y2, Uint32 col, SDL_Surface* srf)
{
  int			x, y;

  for (y = y1; y < y2; ++y)
    {
      x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
      SDLazy_SetPix_Secure(srf, x, y, col);
    }
}

static void		_line(int x1, int y1, int x2, int y2, Uint32 col, SDL_Surface* srf)
{
  if ((x2 - x1) >= (y2 - y1))
    {
      if (x2 < x1)
	_case1(x2, y2, x1, y1, col, srf);
      else
	_case1(x1, y1, x2, y2, col, srf);
    }
  else
    {
      if (y2 < y1)
	_case2(x2, y2, x1, y1, col, srf);
      else
	_case2(x1, y1, x2, y2, col, srf);
    }
}

void			drawLine(Graph *g, double x1, double y1, double x2, double y2, Uint32 col)
{
  _line(g->ori[X] + x1 * (g->unit_dist[X] / g->unit[X]),
	g->ori[Y] + y1 * (g->unit_dist[Y] / -g->unit[Y]),
	g->ori[X] + x2 * (g->unit_dist[X] / g->unit[X]),
	g->ori[Y] + y2 * (g->unit_dist[Y] / -g->unit[Y]),
	col, g->srf);
}
