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
OBJ		+=	src/graph_convertUnity.o
OBJ		+=	src/initGraph.o
OBJ		+=	src/eventsGraph.o
OBJ		+=	src/drawGraph.o
OBJ		+=	src/drawLine.o
OBJ		+=	src/drawDot.o
OBJ		+=	src/zoomGraph.o

$(NAME)		:	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
