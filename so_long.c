/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:20:15 by amaligno          #+#    #+#             */
/*   Updated: 2023/03/28 18:29:33 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

void	rectangle(t_data *img, int xs, int ys)
{
	int	y ;
	int	x ;

	x = -1;
	while (++x < xs)
	{
		y = -1;
		while (++y < ys)
		{
			img->addr = mlx_get_data_addr(img->img, &img->bits, &img->line,
					&img->endian);
			put_pixel(img, x, y, 0x0000FF);
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		*pos[2];
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hi :)");
	img.img = mlx_new_image(mlx, 1920, 1080);
	rectangle(&img, 1000, 1000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
