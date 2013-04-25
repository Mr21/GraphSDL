#include		<math.h>
#include		"graph.h"

#define			SUB_DIV		6
#define			MARGE		10

static int		_pos_text(Graph *g, SDL_Surface *srf, char wh)
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

static void 		_draw_unit_line(Graph *g, int i, double d, char wh)
{
  static SDL_Color	col = {192, 192, 192, 0};
  char			s[32], ok = 0;
  SDL_Surface		*srf;
  SDL_Rect		r;

  sprintf(s, "%+G", d);
  if (!(srf = TTF_RenderText_Solid(g->font, s, col)))
    fprintf(stderr, "TTF_RenderText_Solid failed : %s\n", TTF_GetError());
  if (!wh)
    {
      if (i < g->ori[Y] - 5 || i > g->ori[Y] + 5)
	{
	  ok = 1;
	  graph_drawLineW(g->srf, i, g->col[1], DASHED);
	  r.x = _pos_text(g, srf, wh);
	  r.y = i - srf->h / 2;
	}
    }
  else if (i < g->ori[X] - 5 || i > g->ori[X] + 5)
    {
      ok = 1;
      graph_drawLineH(g->srf, i, g->col[1], DASHED);
      r.x = i - srf->w / 2;
      r.y = _pos_text(g, srf, wh);
    }
  if (ok)
    SDL_BlitSurface(srf, NULL, SDLazy_GetScreen(), &r);
  SDL_FreeSurface(srf);
}

static void		_drawMine(Graph* g)
{
  graph_drawLine(g,
		 3.14, 1.0,
		 9.20, 3.0,
		 0xff0000);
}

void			graph_draw(void)
{
  Graph*		g = SDLazy_GetData();
  double		x = fmod(g->ori[X], g->unit_dist[X]) - g->unit_dist[X];
  double		y = fmod(g->ori[Y], g->unit_dist[Y]) - g->unit_dist[Y];
  double		i, d;
  int			j;

  SDL_FillRect(g->srf, NULL, 0);
  d = (x - g->ori[X]) / g->unit_dist[X] * g->unit[X];
  for (i = x, j = 1; (i += g->unit_dist[X] / SUB_DIV) < g->srf->w; ++j)
    if (j % SUB_DIV)
      graph_drawLineH(g->srf, i, g->col[2], DOTTED);
    else
      _draw_unit_line(g, i, (d += g->unit[X]), 1);
  d = (y - g->ori[Y]) / g->unit_dist[Y] * -g->unit[Y];
  for (i = y, j = 1; (i += g->unit_dist[Y] / SUB_DIV) < g->srf->h; ++j)
    if (j % SUB_DIV)
      graph_drawLineW(g->srf, i, g->col[2], DOTTED);
    else
      _draw_unit_line(g, i, (d -= g->unit[Y]), 0);
  graph_drawLineW(g->srf, g->ori[Y], g->col[0], SOLID);
  graph_drawLineH(g->srf, g->ori[X], g->col[0], SOLID);
  if (!graph_isDragging(g))
    {
      g->ori[X] += (g->drag_smooth[X] /= DRAG_SMOOTH_SPEED);
      g->ori[Y] += (g->drag_smooth[Y] /= DRAG_SMOOTH_SPEED);
    }
  _drawMine(g);
}
