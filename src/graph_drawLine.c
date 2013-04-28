#include		"graph.h"

static void		_case1(int x1, int y1, int x2, int y2, Uint32 col, SDL_Surface* srf)
{
  int			x, y;

  for (x = x1; x < x2; ++x)
    {
      y = y1 + ((y2 - y1) * (x - x1)) / (x2 - x1);
      SDLazy_SetPix(srf, x, y, col);
    }
}

static void		_case2(int x1, int y1, int x2, int y2, Uint32 col, SDL_Surface* srf)
{
  int			x, y;

  for (y = y1; y < y2; ++y)
    {
      x = x1 + ((x2 - x1) * (y - y1)) / (y2 - y1);
      SDLazy_SetPix(srf, x, y, col);
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

static int		_seg2seg(double* A, double* B, double* C, double* D, double* ptInt)
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
  ptInt[X] = Sx;
  ptInt[Y] = Sy;
  return 1;
}

void			graph_drawLine(Graph const* g, double x1, double y1, double x2, double y2, Uint32 col)
{
  double		b[4][2][2];
  double		v[2][2];
  double		newV[2][2];
  int			i, j, aBorder = -1;
  char			displayLine = 0;

  v[0][X] = x1;
  v[0][Y] = y1;
  v[1][X] = x2;
  v[1][Y] = y2;

  newV[0][X] = x1;
  newV[0][Y] = y1;
  newV[1][X] = x2;
  newV[1][Y] = y2;

  b[0][0][X] = g->scrCoordA[X];
  b[0][0][Y] = g->scrCoordA[Y];
  b[0][1][X] = g->scrCoordB[X];
  b[0][1][Y] = g->scrCoordA[Y];

  b[1][0][X] = g->scrCoordB[X];
  b[1][0][Y] = g->scrCoordA[Y];
  b[1][1][X] = g->scrCoordB[X];
  b[1][1][Y] = g->scrCoordB[Y];

  b[2][0][X] = g->scrCoordB[X];
  b[2][0][Y] = g->scrCoordB[Y];
  b[2][1][X] = g->scrCoordA[X];
  b[2][1][Y] = g->scrCoordB[Y];

  b[3][0][X] = g->scrCoordA[X];
  b[3][0][Y] = g->scrCoordB[Y];
  b[3][1][X] = g->scrCoordA[X];
  b[3][1][Y] = g->scrCoordA[Y];

  for (i = 0; i < 2; ++i)
    if (v[i][X] > g->scrCoordA[X] && v[i][X] < g->scrCoordB[X] &&
	v[i][Y] < g->scrCoordA[Y] && v[i][Y] > g->scrCoordB[Y])
      displayLine = 1;
    else
      for (j = 0; j < 4; ++j)
	if (j != aBorder && _seg2seg(v[0], v[1], b[j][0], b[j][1], newV[i]))
	  {
	    aBorder = j;
	    break;
	  }

  if (displayLine || aBorder > -1)
    _line(graph_XtoPixel(newV[0][X]), graph_YtoPixel(newV[0][Y]),
	  graph_XtoPixel(newV[1][X]), graph_YtoPixel(newV[1][Y]),
	  col, g->srf);
}
