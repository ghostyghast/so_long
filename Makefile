SRCS = $(wildcard Resources/*.c) \
		$(wildcard Resources/libft/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra 

MLX = -lmlx -framework OpenGL -framework AppKit

LEAK = -Wall -Werror -Wextra -fsanitize=address -g3

RAW = gcc

NAME = so_long

%.o : %.c
	@$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(SRCS)

$(LEAK): 
	@$(CC) $(LEAK) $(MLX) -o $(NAME) $(SRCS)

$(RAW):
	@$(RAW) $(MLX) -o $(NAME) $(SRCS)

all: $(NAME)

leak: $(LEAK)

raw: $(RAW)

clean: 
	@rm -f $(OBJS)
	@echo "clean!"
	

fclean: clean
	@rm -f $(NAME)
	@echo "fclean!"

re: fclean all
