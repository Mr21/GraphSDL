#ifndef		GRAPH_H
# define	GRAPH_H

# include	<SDL/SDL_ttf.h>
# include	<math.h>
# include	"SDLazy/SDLazy.h"

# define	DRAG_SMOOTH_SPEED	1.07

enum{X,Y,W,H};

typedef		enum
{
  SOLID,
  DASHED,
  DOTTED
}		e_border;

typedef		struct
{
  Uint32	col[6];
  SDL_Surface*	srf;
  TTF_Font*	font;
  double	x, y;
  double	ori[2];
  double	unit[2];
  double	unit_dist[2];
  char		dragging;
  int		drag[2];
  double	drag_smooth[2];
}		Graph;

int		graph_init(Graph*, SDL_Surface*);

/* Zoom */
void		graph_zoomIn(Graph*);
void		graph_zoomOut(Graph*);

/* Drag */
void		graph_dragOn(Graph*);
void		graph_dragOff(Graph*);
int		graph_isDragging(Graph const*);

/* Unity */
int		graph_XtoPixel(double x);
int		graph_YtoPixel(double y);
double		graph_XtoDouble(int x);
double		graph_YtoDouble(int y);

/* Core */
void		graph_core(void);

/* Draw */
void		graph_draw(void);
void		graph_drawDot(Graph const*, double x, double y, Uint32 col);
void		graph_drawLine(Graph const*, double x1, double y1, double x2, double y2, Uint32 col);
void		graph_drawLineW(SDL_Surface*, int x, Uint32 px, e_border);
void		graph_drawLineH(SDL_Surface*, int x, Uint32 px, e_border);

/* Events */
void		graph_eventQuit       (SDL_Event*);
void		graph_eventKeyDown    (SDL_Event*);
void		graph_eventButtonDown (SDL_Event*);
void		graph_eventButtonUp   (SDL_Event*);
void		graph_eventMouseMotion(SDL_Event*);

#endif
