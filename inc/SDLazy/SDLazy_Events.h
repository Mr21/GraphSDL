#ifndef			SDLAZY_EVENTS_H
# define		SDLAZY_EVENTS_H

# include		<SDL/SDL.h>

typedef			struct
{
  int			nb_f;
  int			sz_f;
  int			(**f)(SDL_Event*);
}			SDLazy_Event;

int			SDLazy_AddEvent(Uint8 type, int (*func)(SDL_Event*));
int			SDLazy_DelEvent(Uint8 type, int (*func)(SDL_Event*));

int			SDLazy_EventsUpdate(void);

/* Events par defaut */
int			SDLazy_ResizeEvent(SDL_Event* e);

#endif			/* !SDLAZY_EVENTS_H_ */
