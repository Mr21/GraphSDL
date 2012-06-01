#ifndef			SDLAZY_SURFACES_H_
# define		SDLAZY_SURFACES_H_

# include		<SDL/SDL.h>

typedef			struct
{
  SDL_Surface*		src;
  SDL_Rect		src_r;
  Uint8			to_free;
  char*			path;
}			SDLazy_Surface;

typedef			struct
{
  Uint32		nb_srfs;
  SDLazy_Surface*	srfs;
}			SDLazy_Surfaces;

void			SDLazy_SurfaceLoad(Uint32 id, char* path, SDL_Rect* src_r);
void			SDLazy_SurfacePack(Uint32 id, SDL_Surface* ptr, SDL_Rect* src_r);
void			SDLazy_FreeSurfaces(SDLazy_Surfaces* s);

void			SDLazy_Blit(Uint32 id, SDL_Surface* dst, SDL_Rect* dst_r);
void			SDLazy_BlitScreen(Uint32 id, SDL_Rect* dst_r);

/* Getters */
SDLazy_Surface*		SDLazy_GetSurface(Uint32 id);
int			SDLazy_GetSurfaceW(Uint32 id);
int			SDLazy_GetSurfaceH(Uint32 id);
SDL_Surface*		SDLazy_GetScreen(void);
int			SDLazy_GetScreenW(void);
int			SDLazy_GetScreenH(void);

#endif			/* !SDLAZY_SURFACES_H_ */
