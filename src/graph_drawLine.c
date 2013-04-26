#include		"graph.h"

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
  int			div = x2 - x1;
  double		coefDir = div != 0;

  if (coefDir)
    coefDir = (y2 - y1) / div;

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

static void		_calcDot(Graph const* g, double* x, double* y)
{
  *x = graph_XtoPixel(*x);
  *y = graph_YtoPixel(*y);
  /* Si le point est en dehors de l'ecran */
  if (*x < g->scrCoord[X] || *x > g->scrCoord[X] + g->scrDim[W] ||
      *y < g->scrCoord[Y] || *y > g->scrCoord[Y] + g->scrDim[H])
    {
      
    }
}

void			graph_drawLine(Graph const* g, double x1, double y1, double x2, double y2, Uint32 col)
{
  _calcDot(g, &x1, &y1);
  _calcDot(g, &x2, &y2);
  _line(x1, y1, x2, y2,	col, g->srf);
}
