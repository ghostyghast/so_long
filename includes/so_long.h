/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:25:03 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/08 15:58:12 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"

# define FRAMES 120

enum {
	SPRITE_SIZE = 64,
	FRAM_COIN = 3,
	FRAM_PLYR = 2,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
};

// enum {
// 	SPRITE_SIZE = 64,
// 	FRAM_COIN = 3,
// 	FRAM_PLYR = 2,
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_DESTROY = 17,
// 	KEY_UP = 65362,				Wsl keys
// 	KEY_DOWN = 65364,
// 	KEY_LEFT = 65361,
// 	KEY_RIGHT = 65363,
// 	KEY_ESC = 65307,
// 	KEY_W = 13,
// 	KEY_A = 0,
// 	KEY_S = 1,
// 	KEY_D = 2
// };

typedef struct s_pce
{
	int	p;
	int	c;
	int	e;
}	t_pce;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_flood
{
	int	s_x;
	int	s_y;
	int	b_y;
	int	b_x;
}	t_flood;

typedef struct s_info
{
	int	counter;
	int	coins;
	int	exit;
}	t_info;

typedef struct s_sprite
{
	void	*wall;
	void	*player;
	void	**an_p;
	void	*floor;
	void	*coin;
	void	**an_c;
	void	*exit_open;
	void	*exit_closed;
	void	*enemy;
	void	**an_en;
}	t_sprite;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			move_count;
	int			coin_count;
	t_pos		size;
	t_pos		p_pos;
	t_pos		e_pos;
	t_sprite	sprite;
}	t_data;

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

void	render(t_data *data);
int		animate(t_data *data);
void	init(t_data *data, char *str);
void	freemap(char **str);
void	loop(char *str);
int		exit_prog(t_data *data, int i);
int		path_check(char **map, int lw, t_pce pce);
int		parser(char *map);
int		strline(char *str);
char	**str_alloc(char *map, int *lw);

#endif

// typedef struct s_img
// {
// 	void	*img;
// 	char	*path;
// 	int		width;
// 	int		height;
// }			t_img;

// typedef struct s_pix
// {
// 	void	*img;
// 	void	*addr;	
// 	int		bits;
// 	int		line;
// 	int		endian;
// }			t_pix;