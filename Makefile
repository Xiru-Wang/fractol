RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_PATH = minilibx-linux
MLX = minilibx-linux/libmlx.a

LIB = fractol.h
SRC = main.c \
	events.c \
	julia.c \
	mandel.c \
	utils.c \
	burning_ship.c

OBJS = $(SRC:.c=.o)

all:		$(NAME) $(MLX)

$(NAME): $(OBJS)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm -o $(NAME)
	@echo "$(NAME) : $(GREEN)$(OBJS) was created $(RESET)"

clean:
		rm -f $(OBJS)
		@make clean -C $(MLX_PATH)
		@echo "$(RED)$(OBJS) was deleted $(RESET)"

fclean: clean
		rm -f $(NAME) $(MLX)
		@echo "$(RED)$(NAME) $(mlx) was deleted $(RESET)"

re:		fclean all

.PHONY: all clean fclean re
