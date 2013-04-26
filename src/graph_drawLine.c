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

static int		_seg2seg(double* A, double* B, double* C, double* D, double* Ix, double* Iy)
{
  double Ax = A[X];
  double Ay = A[Y];
  double Bx = B[X];
  double By = B[Y];
  double Cx = C[X];
  double Cy = C[Y];
  double Dx = D[X];
  double Dy = D[Y];
  double Sx;
  double Sy;

  if (Ax == Bx)
    {
      if (Cx == Dx)
	return 0;
      else
	{
	  double pCD = (Cy - Dy) / (Cx - Dx);
	  Sx = Ax;
	  Sy = pCD * (Ax - Cx) + Cy;
	}
    }
  else
    {
      if (Cx == Dx)
	{
	  double pAB = (Ay - By) / (Ax - Bx);
	  Sx = Cx;
	  Sy = pAB * (Cx - Ax) + Ay;
	}
      else
	{
	  double pCD = (Cy - Dy) / (Cx - Dx);
	  double pAB = (Ay - By) / (Ax - Bx);
	  double oCD = Cy - pCD * Cx;
	  double oAB = Ay - pAB * Ax;
	  Sx = (oAB - oCD) / (pCD - pAB);
	  Sy = pCD * Sx + oCD;
	}
    }
  if ((Sx < Ax && Sx < Bx) || (Sx > Ax && Sx > Bx) || (Sx < Cx && Sx < Dx) || (Sx > Cx && Sx > Dx) ||
      (Sy < Ay && Sy < By) || (Sy > Ay && Sy > By) || (Sy < Cy && Sy < Dy) || (Sy > Cy && Sy > Dy))
    return 0;
  *Ix = Sx;
  *Iy = Sy;
  return 1;
}

static int		_calcDot(Graph const* g, double* x, double* y)
{
  /* Si le point est en dehors de l'ecran */
  if (*x < g->scrCoordA[X] || *x > g->scrCoordB[X] ||
      *y > g->scrCoordA[Y] || *y < g->scrCoordB[Y])
    {
      printf("%+8.2f | %+8.2f\n", *y, g->scrCoordA[Y]);
      return 0;
    }
  *x = graph_XtoPixel(*x);
  *y = graph_YtoPixel(*y);
  return 1;
}

void			graph_drawLine(Graph const* g, double x1, double y1, double x2, double y2, Uint32 col)
{
  /*  double		a1[2], a2[2];
  double		b1[2], b2[2];

  a1[X] = x1;
  a1[Y] = y1;
  a2[X] = x2;
  a2[Y] = y2;*/

  /*if (_seg2seg(double* A, double* B, double* C, double* D, *x, *y))*/

  _line(graph_XtoPixel(x1), graph_YtoPixel(y1),
	graph_XtoPixel(x2), graph_YtoPixel(y2),
	col, g->srf);
}
