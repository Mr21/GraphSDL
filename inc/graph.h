#ifndef		GRAPH_H
# define	GRAPH_H

# include	<SDL/SDL_ttf.h>
# include	<math.h>
# include	"SDLazy/SDLazy.h"

# define	DRAG_SMOOTH_SPEED	1.1

enum {X, Y};

typedef enum
  {
    SOLID,
    DASHED,
    DOTTED
  } e_border;

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
  int**		data;
  int		nb_lines;
}		Graph;

int		initGraph(Graph*, SDL_Surface*);
void		drawGraph(void);

void		graph_zoomIn(Graph*);
void		graph_zoomOut(Graph*);
int		graph_XtoPixel(double x);
int		graph_YtoPixel(double y);

void		drawLineW(SDL_Surface*, int x, Uint32 px, e_border);
void		drawLineH(SDL_Surface*, int x, Uint32 px, e_border);
void		graph_draw_bar(Graph*, double x, double sz, Uint32 col);
void		drawDot(Graph*, double x, double y, Uint32 col);
void		drawLine(Graph*, double x1, double y1, double x2, double y2, Uint32 col);

/* Events */
void		eventQuit(SDL_Event*);
void		eventKeyDown(SDL_Event*);
void		eventButtonDown(SDL_Event*);
void		eventButtonUp(SDL_Event*);
void		eventMouseMotion(SDL_Event*);

#endif
