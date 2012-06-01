#ifndef				GRAPH_H
# define			GRAPH_H

# include			<SDL/SDL_ttf.h>
# include			<math.h>
# include			"SDLazy/SDLazy.h"

# define			DRAG_SMOOTH_SPEED	1.1

enum {X, Y};

typedef enum
  {
    SOLID,
    DASHED,
    DOTTED
  } e_border;

typedef				struct
{
  Uint32			col[6];
  SDL_Surface*			srf;
  TTF_Font*			font;
  double			x;
  double			y;
  double			ori[2];
  double			unit[2];
  double			unit_dist[2];
  char				dragging;
  int				drag[2];
  double			drag_smooth[2];

  int**				data;
  int				nb_lines;

}				Graph;

int				initGraph(Graph* g, SDL_Surface* srf);
int				drawGraph(void);
void				zoomGraph(Graph* g, int zoom);

void				drawLineW(SDL_Surface* srf, int x, Uint32 px, e_border style);
void				drawLineH(SDL_Surface* srf, int x, Uint32 px, e_border style);
void				graph_draw_bar(Graph* g, double x, double sz, Uint32 col);
void				drawDot(Graph* g, double x, double y, Uint32 col);
void				drawLine(Graph* g, double x1, double y1, double x2, double y2, Uint32 col, SDL_Surface* srf);

/* Events */
int				eventQuit(SDL_Event* e);
int				eventKeyDown(SDL_Event* e);
int				eventButtonDown(SDL_Event* e);
int				eventButtonUp(SDL_Event* e);
int				eventMouseMotion(SDL_Event* e);

#endif
