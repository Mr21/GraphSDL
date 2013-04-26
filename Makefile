NAME		=	graph2d
CC		=	gcc
RM		=	@rm -f

CFLAGS		=	-Wall -Wextra -pedantic
CFLAGS		+=	-Iinc/

LDFLAGS		=	-lm
LDFLAGS		+=	-lSDL
LDFLAGS		+=	-lSDL_image
LDFLAGS		+=	-lSDL_ttf

OBJ		=	src/SDLazy.o
OBJ		+=	src/main.o
OBJ		+=	src/graph_init.o
OBJ		+=	src/graph_draw.o
OBJ		+=	src/graph_core.o
OBJ		+=	src/graph_events.o
OBJ		+=	src/graph_unity.o
OBJ		+=	src/graph_drag.o
OBJ		+=	src/graph_zoom.o
OBJ		+=	src/graph_drawLine.o
OBJ		+=	src/graph_drawDot.o

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
