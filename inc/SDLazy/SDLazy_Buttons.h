#ifndef			SDLAZY_BUTTONS_H
# define		SDLAZY_BUTTONS_H

# include		<SDL/SDL.h>
# include		"list.h"

typedef			enum
  {
    BUTTON_MOUSEOVER,
    BUTTON_MOUSEOUT,
    BUTTON_CLICDOWN,
    BUTTON_CLICUP,
    NB_BUTTON_EVENTS
  }			eButtonEvent;

typedef			enum
  {
    BUTTON_UP,
    BUTTON_UP_HOVER,
    BUTTON_PRESSED_0,
    BUTTON_DOWN,
    BUTTON_DOWN_HOVER,
    BUTTON_PRESSED_1,
    NB_BUTTON_STATUS
  }			eButtonStatus;

typedef			enum
  {
    BUTTON_SIMPLE,
    BUTTON_DOUBLE
  }			eButtonType;

typedef			struct
{
  SDL_Rect		pos;
  unsigned		srf[NB_BUTTON_STATUS];
  unsigned		srf_curr;
  int			(*f[NB_BUTTON_EVENTS])();
  eButtonType		type;
  char			enable;
  char			status;
  char			pressed;
  char			hover;
}			SDLazy_Button;

typedef			struct
{
  t_list		list;
}			SDLazy_Buttons;

SDLazy_Button*		SDLazy_ButtonCreate(eButtonType type, int x, int y);
void			SDLazy_FreeButtons(SDLazy_Buttons* btns);
void			SDLazy_ButtonBlit(SDLazy_Button* btn, SDL_Surface* srf);

/* Setters */
void			SDLazy_ButtonEnable(SDLazy_Button* btn, int enable);
void			SDLazy_ButtonSetType(SDLazy_Button* btn, eButtonType type);

void			SDLazy_ButtonSetSrf(SDLazy_Button* btn, eButtonStatus st, unsigned srf);
void			SDLazy_ButtonSetFun(SDLazy_Button* btn, eButtonEvent ev, int (*f)());

void			SDLazy_ButtonSetPos(SDLazy_Button* btn, int x, int y);
void			SDLazy_ButtonSetPosX(SDLazy_Button* btn, int x);
void			SDLazy_ButtonSetPosY(SDLazy_Button* btn, int y);


/* Events */
int			SDLazy_ButtonMousemotionEvent(SDL_Event*);
int			SDLazy_ButtonClicDownEvent(SDL_Event*);
int			SDLazy_ButtonClicUpEvent(SDL_Event*);

#endif			/* !SDLAZY_BUTTONS_H */
