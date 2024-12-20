/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:25:03 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/24 15:05:51 by pringles         ###   ########.fr       */
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

# define FRAMES 60
# define ENEMY_SPEED 20

enum
{
	SPRITE_SIZE = 64,
	FRAM_COIN = 2,
	FRAM_WALL = 12,
	FRAM_PLYR = 2,
};

# ifdef __APPLE__

enum e_keys
{
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

# elif __linux__
# include "X11/keysym.h"

enum 
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_DESTROY = 17,
	KEY_UP = XK_Up,
	KEY_DOWN = XK_Down,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
	KEY_ESC = XK_Escape,
	KEY_W = XK_w,
	KEY_A = XK_a,
	KEY_S = XK_s,
	KEY_D = XK_d
};
#endif

// enum {
// 	SPRITE_SIZE = 64,
// 	FRAM_COIN = 3,
// 	FRAM_PLYR = 2,
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_DESTROY = 17,
// 	KEY_UP = 65362,
// 	KEY_DOWN = 65364,			WSL keycodes
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
	void	**an_w;
	void	*plyr;
	void	**an_p;
	void	*floor;
	void	*coin;
	void	**an_c;
	void	*e_cl;
	void	*e_op;
	void	*enemy;
}	t_sprite;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			move_count;
	int			coin_count;
	int			enemy_count;
	t_pos		*enemies;
	t_pos		size;
	t_pos		p_pos;
	t_pos		e_pos;
	t_sprite	sprite;
}	t_data;

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

t_pos	direction(t_pos pos, int dir);
void	printmap(char **map);
void	enemy_spawncheck(t_data *data);
void	move_enemies(t_pos *enemies, int enemy_count, char **map, t_data *data);
int		check_and_move(char **map, t_pos *pos, int mode, t_data *data);
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