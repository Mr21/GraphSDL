#ifndef				SDLAZY_H_
# define			SDLAZY_H_

# include			<SDL/SDL.h>
# include			<SDL/SDL_image.h>

# include			"SDLazy_Cursors.h"
# include			"SDLazy_Events.h"
# include			"SDLazy_Surfaces.h"
# include			"SDLazy_Buttons.h"
# include			"SDLazy_Anims.h"

# include			"SDLazy_Circle.h"

typedef				struct
{
  void*				data;
  const char*			title;
  Uint32			fps_delay;
  SDLazy_Cursors		cursors;
  SDLazy_Surfaces		surfaces;
  SDLazy_Buttons		buttons;
  SDLazy_Anims			anims;
  Uint32			flags;
  SDL_Surface*			scr;
  SDLazy_Event			e[SDL_USEREVENT];
  double			frameTime;
}				SDLazy;

extern SDLazy			g_sdlazy;

void				SDLazy_Init(int w, int h, Uint32 flags, const char* title);
void				SDLazy_Loop(void* data, int (*core)(void), int (*render)(void));
void				SDLazy_Quit(char* msg);
SDL_Rect*			SDLazy_Rect(int x, int y, int w, int h);
int				SDLazy_Fullscreen(void);

/* Getters / Setters */
void*				SDLazy_GetData(void);
double				SDLazy_GetFrameTime(void);
void				SDLazy_SetFps(Uint32 delay);

/*
** Acces aux pixels d'une surface
** Les fonctions _Secure s'assure que x et y soit bien des coordonnees valides
*/
void				SDLazy_SetPix(SDL_Surface *srf, int x, int y, Uint32 px);
Uint32                          SDLazy_GetPix(SDL_Surface* srf, int x, int y);
void				SDLazy_SetPix_Secure(SDL_Surface *srf, int x, int y, Uint32 px);
Uint32                          SDLazy_GetPix_Secure(SDL_Surface* srf, int x, int y);

#endif				/* !SDLAZY_H_ */
