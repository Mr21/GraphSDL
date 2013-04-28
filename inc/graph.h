#ifndef		GRAPH_H
# define	GRAPH_H

# include	<SDL/SDL_ttf.h>
# include	<math.h>
# include	"SDLazy/SDLazy.h"

# define	DRAG_SMOOTH_SPEED	1.07

typedef	struct Graph Graph;

enum{X,Y};

typedef		enum
{
  SOLID,
  DASHED,
  DOTTED
}		e_border;

struct		Graph
{
  Uint32	col[6];
  void		(*userCore)(Graph*);
  void		(*userRender)(Graph const*);
  SDL_Surface*	srf;
  TTF_Font*	font;
  double	scrCoordA[2];
  double	scrCoordB[2];
  double	scrDim[2];
  double	x, y;
  double	ori[2];
  double	unit[2];
  double	unit_dist[2];
  char		dragging;
  int		drag[2];
  double	drag_smooth[2];
};

/* Init */
int		graph_init(Graph*, void (*userCore)(Graph*), void (*userRender)(Graph const*), SDL_Surface*);

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
void		graph_calcScreenCoord(Graph*);
void		graph_calcScreenDim(Graph*);

/* Draw */
void		graph_draw(void);
void		graph_drawDot(Graph const*, double x, double y, Uint32 col);
void		graph_drawLine(Graph const*, double x1, double y1, double x2, double y2, Uint32 col);
void		graph_drawLineW(SDL_Surface*, int x, Uint32 px, e_border);
void		graph_drawLineH(SDL_Surface*, int x, Uint32 px, e_border);

/* Events */
void		graph_eventQuit       (SDL_Event*);
void		graph_eventResize     (SDL_Event*);
void		graph_eventKeyDown    (SDL_Event*);
void		graph_eventButtonDown (SDL_Event*);
void		graph_eventButtonUp   (SDL_Event*);
void		graph_eventMouseMotion(SDL_Event*);

#endif
