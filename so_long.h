/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:25:03 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/12 18:20:37 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
// # include "Resources/libft/ft_printf.h"
// # include "Resources/libft/get_next_line.h"

// enum
// {
// }

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

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

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}			t_img;

int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);

void	freemap(char **str);
void	render(char *str);
int		path_check(char **map, int lw, t_pce pce);
int		parser(char *map);
int		strline(char *str);

#endif

// typedef struct s_pix
// {
// 	void	*img;
// 	void	*addr;	
// 	int		bits;
// 	int		line;
// 	int		endian;
// }			t_pix;