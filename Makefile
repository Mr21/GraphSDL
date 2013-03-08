NAME		=	graph2d
CC		=	gcc
RM		=	@rm -f

CFLAGS		=	-Wall -Wextra -pedantic
CFLAGS		+=	-Iinc/

LDFLAGS		=	-lm
LDFLAGS		+=	-lSDL
LDFLAGS		+=	-lSDL_image-1.2
#LDFLAGS		+=	-lSDL_ttf-2.0
LDFLAGS		+=	/usr/lib64/libSDL_ttf-2.0.so.0.10.1

OBJ		=	src/SDLazy.o
OBJ		+=	src/main.o
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
