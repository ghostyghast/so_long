SRCS_NAME := init_var.c loop.c parsing.c so_long.c pathcheck.c animate.c

SRCS_DIR := ./src 
OBJS_DIR := ./obj

OBJS := $(SRCS_NAME:%.c=$(OBJS_DIR)/%.o)

CC := gcc

RAW = gcc

CFLAGS := -Wall -Werror -Wextra

MLX := -lmlx -framework OpenGL -framework AppKit

WIN = -lmlx -lXext -lX11 -lm -lz

LEAK = -Wall -Werror -Wextra -fsanitize=address -g3

NAME := so_long

INCLUDES := -Iincludes -Ilibft

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(INCLUDES) -Imlx -c $< -o $@  

$(NAME): $(OBJS)
	@make -C ./libft 
	@$(CC) $(CFLAGS) $(INCLUDES) $(MLX) -o $@ $(OBJS) -lft -L./libft

$(LEAK): 
	@$(CC) $(LEAK) $(MLX) -o $(NAME) $(SRCS)

$(RAW):
	@$(RAW) $(MLX) -o $(NAME) $(SRCS)

$(WIN):
	@$(CC) $(SRCS) $(CFLAGS) $(MLX_WIN) -o $(NAME)

all: $(NAME)

win: $(WIN)

leak: $(LEAK)

raw: $(RAW)

clean: 
	@rm -rf src/obj
	@make clean -C ./libft
	@echo "clean!"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "fclean!"

re: fclean all
