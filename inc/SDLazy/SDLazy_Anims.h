#ifndef			SDLAZY_ANIMS_H
# define		SDLAZY_ANIMS_H

# include		"SDLazy_Surfaces.h"
# include		"list.h"

# define		TIMER_DEFAULT		50

typedef			enum
  {
    ANIM_PLAYING,
    ANIM_PAUSE,
    ANIM_STOP
  }			eAnimStatus;

typedef			struct
{
  SDLazy_Surface*	srf;
  SDL_Rect		r_start;
  eAnimStatus		pause_or_stop;
  eAnimStatus		status;
  int			x_rel;
  int			nb_frames;
  int			frame_curr;
  int			frame_loop;
  unsigned		ms_curr;
  unsigned		ms_interval;
}			SDLazy_Anim;

typedef			struct
{
  unsigned		timer_default;
  t_list		list;
}			SDLazy_Anims;

/* AnimS */
void			SDLazy_InitAnims(SDLazy_Anims*);
void			SDLazy_FreeAnims(SDLazy_Anims*);

SDLazy_Anim*		SDLazy_AnimCreate(unsigned srf, int nb_frames, int frame_loop, eAnimStatus status);
void			SDLazy_FreeAnim(SDLazy_Anim*);

/* Blit */
void			SDLazy_AnimBlit(SDLazy_Anim*, SDL_Surface*, SDL_Rect*);
void			SDLazy_AnimBlitScreen(SDLazy_Anim*, SDL_Rect*);

/* Controles */
/*   Sur toutes les animations du programme */
void			SDLazy_AnimsPlay(void);
void			SDLazy_AnimsPause(void);
void			SDLazy_AnimsStop(void);
/*   Sur une animation en particuliere */
void			SDLazy_AnimRewind(SDLazy_Anim*);
void			SDLazy_AnimPlay(SDLazy_Anim*);
void			SDLazy_AnimPause(SDLazy_Anim*);
void			SDLazy_AnimStop(SDLazy_Anim*);

/* Getters / Setters */
eAnimStatus		SDLazy_AnimStatus(SDLazy_Anim*);
void			SDLazy_AnimTimer(SDLazy_Anim*, unsigned ms);
void			SDLazy_AnimsTimer(unsigned ms);
void			SDLazy_AnimFrameLoop(SDLazy_Anim*, int frame);

void			SDLazy_AnimsUpdate(SDLazy_Anims*);

#endif
