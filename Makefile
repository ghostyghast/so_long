SRCS = $(wildcard Resources/*.c) \
		$(wildcard Resources/libft/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc

WIN = gcc

RAW = gcc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

MLX = -lmlx -framework OpenGL -framework AppKit

MLX_WIN = -lmlx -lXext -lX11 -lm -lz

LEAK = -Wall -Werror -Wextra -fsanitize=address -g3

NAME = so_long

%.o : %.c
	@$(CC) -c -o $@ $< $(CFLAGS) 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(SRCS)

$(LEAK): 
	@$(CC) $(LEAK) $(MLX) -o $(NAME) $(SRCS)

$(RAW):
	@$(RAW) $(MLX) -o $(NAME) $(SRCS)

$(WIN):
	@$(WIN) $(SRCS) $(CFLAGS) $(MLX_WIN) -o $(NAME)

all: $(NAME)

win: $(WIN)

leak: $(LEAK)

raw: $(RAW)

clean: 
	@rm -f $(OBJS)
	@echo "clean!"
	

fclean: clean
	@rm -f $(NAME)
	@echo "fclean!"

re: fclean all
