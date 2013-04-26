#include		"graph.h"

void			graph_drawLineW(SDL_Surface *srf, int y, Uint32 px, e_border style)
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
