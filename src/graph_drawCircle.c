#include	"graph.h"

static void	_circle(SDL_Surface* srf, int centerX, int centerY, int r, Uint32 col)
{
  int		x = 0, y = r, d = r - 1;
 
  while (y >= x)
    {
      SDLazy_SetPix_Secure(srf, centerX + x, centerY + y, col);
      SDLazy_SetPix_Secure(srf, centerX + y, centerY + x, col);
      SDLazy_SetPix_Secure(srf, centerX - x, centerY + y, col);
      SDLazy_SetPix_Secure(srf, centerX - y, centerY + x, col);
      SDLazy_SetPix_Secure(srf, centerX + x, centerY - y, col);
      SDLazy_SetPix_Secure(srf, centerX + y, centerY - x, col);
      SDLazy_SetPix_Secure(srf, centerX - x, centerY - y, col);
      SDLazy_SetPix_Secure(srf, centerX - y, centerY - x, col);
      if (d >= 2 * x)
        {
	  d -= 2 * x - 1;
	  ++x;
        }
      else if (d < 2 * (r - y))
        {
	  d += 2 * y - 1;
	  --y;
        }
      else
        {
	  d += 2 * (y - x - 1);
	  --y;
	  ++x;
        }
    }
}

void		graph_drawCircle(Graph const* g, double x, double y, double r, Uint32 col)
{
  _circle(g->srf, graph_XtoPixel(x), graph_YtoPixel(y), graph_scalePixel(r), col);
}
