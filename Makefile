NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = minilibx-linux
LIB = fractol.h
SRC = main.c \
	events.c \
	julia.c \
	mandel.c \
	utils.c \
	newton.c

OBJS = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
