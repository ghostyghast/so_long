/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:20:15 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/12 18:34:10 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	stop(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

// void	put_pixel(t_pix *img, int x, int y, int color)
// {
// 	char	*dst;

// 	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->line,
// 			&img->endian);
// 	dst = img->addr + (y * img->line + x * (img->bits / 8));
// 	*(unsigned int *)dst = color;
// }

// void	rectangle(t_pix *img, int xs, int ys)
// {
// 	int	y;
// 	int	x;

// 	x = -1;
// 	while (++x < xs)
// 	{
// 		y = -1;
// 		while (++y < ys)
// 			put_pixel(img, x, y, 0x0000FF);
// 	}
// }

int	main(void)
{
	t_img	img1;
	t_data	data;
	t_img	img2;

	img1.height = img2.height = 1100;
	img1.width = img2.width = 800;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hi :)");
	img1.img = mlx_xpm_file_to_image(data.mlx, "Resources/Textures/test.xpm", &img1.width, &img1.height);
	img2.img = mlx_xpm_file_to_image(data.mlx, "Resources/Textures/red_circle.xpm", &img2.width, &img2.height);
	// rectangle(&pix, 500, 500);
	mlx_put_image_to_window(data.mlx, data.win, img2.img, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, img2.img, 100, 100);
	mlx_put_image_to_window(data.mlx, data.win, img1.img, 0, 0);
	mlx_key_hook(data.win, stop, &data);
	mlx_loop(data.mlx);
	return (0);
}
