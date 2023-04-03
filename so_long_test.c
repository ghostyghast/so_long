/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:20:15 by amaligno          #+#    #+#             */
/*   Updated: 2023/03/30 16:55:32 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stop(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	put_pixel(t_pix *img, int x, int y, int color)
{
	char	*dst;

	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->line,
			&img->endian);
	dst = img->addr + (y * img->line + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}

void	rectangle(t_pix *img, int xs, int ys)
{
	int	y;
	int	x;

	x = -1;
	while (++x < xs)
	{
		y = -1;
		while (++y < ys)
			put_pixel(img, x, y, 0x0000FF);
	}
}

int	main(void)
{
	t_img	img;
	t_data	data;
	t_pix	pix;

	img.height = 1100;
	img.width = 800;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 500, 1000, "Hi :)");
	img.img = mlx_xpm_file_to_image(data.mlx, "test.xpm", &img.width, &img.height);
	pix.img = mlx_new_image(data.mlx, 500, 500);
	rectangle(&pix, 500, 500);
	mlx_put_image_to_window(data.mlx, data.win, pix.img, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
	mlx_key_hook(data.win, stop, &data);
	mlx_loop(data.mlx);
	return (0);
}
