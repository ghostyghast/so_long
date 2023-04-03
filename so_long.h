 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:25:03 by amaligno          #+#    #+#             */
/*   Updated: 2023/03/29 15:54:47 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "Resources/libft/ft_printf.h"
# include "Resources/libft/get_next_line.h"

// enum
// {
// }

typedef struct s_pce
{
	int	p;
	int	c;
	int	e;
}	t_pce;


typedef struct s_pix
{
	void	*img;
	void	*addr;	
	int		bits;
	int		line;
	int		endian;
}			t_pix;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

#endif