NAME := so_long

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc

WIN = gcc

RAW = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -Iincludes -Ilibft

LIB = -L./libft -lft

MLX = -lmlx -framework OpenGL -framework AppKit

MLX_WIN = -lmlx -lXext -lX11 -lm -lz

LEAK = -Wall -Werror -Wextra -fsanitize=address -g3

NAME = so_long

%.o : %.c
	@$(CC) $(INCLUDES) -c -o $@ $< 

$(NAME): $(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(MLX) -o $@ $(LIB) $(SRCS)

$(LEAK): 
	@$(CC) $(LEAK) $(INCLUDES) $(MLX) -o $@ $(LIB) $(SRCS)

$(RAW):
	@$(RAW) $(MLX) -o $(NAME) $(SRCS)

$(WIN):
	@$(WIN) $(SRCS) $(CFLAGS) $(MLX_WIN) -o $(NAME)

all: $(NAME)

clean: 
	@rm -f src/*.o
	@make clean -C ./libft
	@echo "clean!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "fclean!"

re: fclean all

# $(NAME): $(OBJS)
# 	@make -C ./libft 
# 	@$(CC) $(CFLAGS) $(INCLUDES) $(MLX) -o $@ $(OBJS) -lft -L./libft

