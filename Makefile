NAME		=	graph2d
CC		=	gcc
CFLAGS		=	-Wall -Wextra -pedantic
CFLAGS		+=	-Iinc/
LIB		=	-lSDL -lSDL_image -lSDL_ttf -lm lib/SDLazy.a
RM		=	@rm -f

SRC		=	src/main.c		\
			src/initGraph.c		\
			src/eventsGraph.c	\
			src/drawGraph.c		\
			src/drawLine.c		\
			src/drawDot.c		\
			src/zoomGraph.c		\

OBJ		=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

all		:	$(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean $(NAME)

.PHONY		:	all clean fclean re
