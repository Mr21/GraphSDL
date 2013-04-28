#include		<math.h>
#include		"graph.h"

#define			SUB_DIV		6
#define			MARGE		10

static int		_posText(Graph const* g, SDL_Surface *srf, char wh)
{
  if (wh == X)
    {
      if (g->ori[X] < srf->w + MARGE * 2)
	return MARGE;
      if (g->ori[X] > g->srf->w)
	return g->srf->w - srf->w - MARGE;
      return g->ori[X] - srf->w - MARGE;
    }
  if (g->ori[Y] < srf->h - MARGE)
    return MARGE;
  if (g->ori[Y] > g->srf->h - srf->h - MARGE * 2)
    return g->srf->h - srf->h - MARGE;
  return g->ori[Y] + MARGE;
}

static void 		_drawUnit(Graph const* g, int i, double d, char wh)
{
  static SDL_Color	col = {192, 192, 192, 0};
  char			s[64], ok = 0;
  SDL_Surface*		srf;
  SDL_Rect		r;

  sprintf(s, "%+G", d);
  if (!(srf = TTF_RenderText_Solid(g->font, s, col)))
    fprintf(stderr, "TTF_RenderText_Solid failed : %s\n", TTF_GetError());
  else
    {
      if (!wh)
	{
	  if (i < g->ori[Y] - 5 || i > g->ori[Y] + 5)
	    {
	      ok = 1;
	      graph_drawLineW(g->srf, i, g->col[1], DASHED);
	      r.x = _posText(g, srf, wh);
	      r.y = i - srf->h / 2;
	    }
	}
      else if (i < g->ori[X] - 5 || i > g->ori[X] + 5)
	{
	  ok = 1;
	  graph_drawLineH(g->srf, i, g->col[1], DASHED);
	  r.x = i - srf->w / 2;
	  r.y = _posText(g, srf, wh);
	}
      if (ok)
	SDL_BlitSurface(srf, NULL, g->srf, &r);
      SDL_FreeSurface(srf);
    }
}

static void		_drawOrigins(Graph const* g)
{
  graph_drawLineW(g->srf, g->ori[Y], g->col[0], SOLID);
  graph_drawLineH(g->srf, g->ori[X], g->col[0], SOLID);
}

static void		_drawGrid(Graph const* g)
{
  double		x = fmod(g->ori[X], g->unit_dist[X]) - g->unit_dist[X];
  double		y = fmod(g->ori[Y], g->unit_dist[Y]) - g->unit_dist[Y];
  double		i, d;
  int			j;

  d = (x - g->ori[X]) / g->unit_dist[X] * g->unit[X];
  for (i = x, j = 1; (i += g->unit_dist[X] / SUB_DIV) < g->srf->w; ++j)
    if (j % SUB_DIV)
      graph_drawLineH(g->srf, i, g->col[2], DOTTED);
    else
      _drawUnit(g, i, (d += g->unit[X]), 1);
  d = (y - g->ori[Y]) / g->unit_dist[Y] * -g->unit[Y];
  for (i = y, j = 1; (i += g->unit_dist[Y] / SUB_DIV) < g->srf->h; ++j)
    if (j % SUB_DIV)
      graph_drawLineW(g->srf, i, g->col[2], DOTTED);
    else
      _drawUnit(g, i, (d -= g->unit[Y]), 0);
}

void			_drawMouseCoord(Graph const* g)
{
  static SDL_Color	col = {220, 220, 220, 0};
  static SDL_Rect	r[2] = {{10, 10, 0, 0}, {0, 0, 0, 0}};
  char			str[128];
  SDL_Surface*		srf;

  sprintf(str, "X : %+G", graph_XtoDouble(SDLazy_GetMouseX()));
  if ((srf = TTF_RenderText_Solid(g->font, str, col)))
    {
      if (!r[1].y)
	{
	  r[1] = r[0];
	  r[1].y += 1.5 * srf->h;
	}
      SDL_BlitSurface(srf, NULL, g->srf, r + 0);
      SDL_FreeSurface(srf);
    }
  sprintf(str, "Y : %+G", graph_YtoDouble(SDLazy_GetMouseY()));
  if ((srf = TTF_RenderText_Solid(g->font, str, col)))
    {
      SDL_BlitSurface(srf, NULL, g->srf, r + 1);
      SDL_FreeSurface(srf);
    }
}

void			graph_draw(void)
{
  Graph const*		g = SDLazy_GetData();

  SDL_FillRect(g->srf, NULL, 0);
  _drawGrid(g);
  _drawOrigins(g);
  g->userRender(g);
  _drawMouseCoord(g);
}
