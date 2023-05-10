SRCS_NAME := init_var.c loop.c parsing.c so_long.c pathcheck.c animate.c

SRCS_PREF := $(addprefix src/, $(SRCS_NAME))

SRCS_DIR = /src 
OBJS_DIR = /obj

OBJS := $(SRCS_NAME:%.c=obj/%.o)

CC := gcc

RAW = gcc

CFLAGS := -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework AppKit

MLX_WIN = -Lmlx -lXext -lX11

LEAK = -Wall -Werror -Wextra -fsanitize=address -g3

NAME = so_long

INCLUDES = -Iincludes -Ilibft

obj/%.o : src/%.c
	@mkdir -p obj/
	$(CC) $(INCLUDES) -Imlx -c $< -o $@  

$(NAME): $(OBJS)
	@make -C ./libft 
	@$(CC) $(CFLAGS) $(INCLUDES) $(MLX) -o $@ $(OBJS) -lft -L./libft

$(LEAK): 
	@make -C ./libft 
	@$(CC) $(LEAK) $(MLX) -o $(NAME) $(SRCS)

$(RAW):
	@make -C ./libft 
	@$(RAW) $(MLX) -o $(NAME) $(SRCS)

all: $(NAME)

win: $(OBJS)
	@make -C ./libft 
	@$(CC) $(CFLAGS) $(MLX_WIN) $(INCLUDES) $< -o $(NAME) -lft -L./libft

leak: $(LEAK)

raw: $(RAW)

clean: 
	@rm -rf obj/
	@make clean -C ./libft
	@echo "clean!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "fclean!"

re: fclean all
