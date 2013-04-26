#include		"graph.h"

void			graph_drawLineH(SDL_Surface *srf, int x, Uint32 px, e_border style)
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
