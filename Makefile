SRCS	=	srcs/main.c\
			srcs/io.c\
			srcs/parsing.c\
			srcs/draw.c\
			srcs/render.c\
			srcs/error.c\
			srcs/others.c\
			srcs/snapshot.c

OBJS	=	${SRCS:.c=.o}

NAME	=	Cub3D

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I. 

all:		${NAME}

${NAME}:	${OBJS}
			make -C mlx/
			make -C libft/
			${CC} ${CFLAGS} ${OBJS} -framework OpenGL -framework AppKit -Lmlx/ -lmlx -Llibft/ -lft -o ${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME} screenshot.bmp

re:			fclean all

bonus:		all
