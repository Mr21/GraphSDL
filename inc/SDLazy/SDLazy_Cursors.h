#ifndef			SDLAZY_CURSORS
# define		SDLAZY_CURSORS

# include		<SDL/SDL.h>

typedef			enum
  {
    CURSOR_ARROW,
    CURSOR_POINTER,
    CURSOR_OPEN_HAND,
    CURSOR_CLOSE_HAND,

    CURSOR_TOTAL
  }			eCursor;

typedef			struct
{
  SDL_Cursor*		tab[CURSOR_TOTAL];
}			SDLazy_Cursors;

void			SDLazy_InitCursors(SDLazy_Cursors* curs);
void			SDLazy_FreeCursors(SDLazy_Cursors* curs);
void			SDLazy_SetCursor(eCursor cur);

#endif			/* !SDLAZY_CURSORS */
