SRCS = $(wildcard *.c) 

OBJS = $(SRCS:.c=.o)

OBJS_DIR = objs/

OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

MLX = -lmlx -framework OpenGL -framework AppKit

LEAK = -Wall -Werror -Wextra -fsanitize=address -g3

NAME = so_long

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS_PREFIXED)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(SRCS)

$(LEAK): 
	@$(CC) $(LEAK) $(MLX) -o $(NAME) $(SRCS)

all: $(NAME)

leak: $(LEAK)

clean: 
	@rm -f $(OBJS_PREFIXED)
	@echo "clean!"
	

fclean: clean
	@rm -f $(NAME)
	@echo "fclean!"

re: fclean all
