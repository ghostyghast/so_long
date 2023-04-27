/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:20:15 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/26 14:25:49 by amaligno         ###   ########.fr       */
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
	void	*img1;
	t_data	data;
	void	*img2;

	int h1 = 0; 
	int h2  = 0;
	int w1  = 0;
	int w2  = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hi :)");
	img1 = mlx_xpm_file_to_image(data.mlx, "Resources/Textures/test.xpm", &w1, &h1);
	img2 = mlx_xpm_file_to_image(data.mlx, "Resources/Textures/red_circle.xpm", &w2, &h2);
	// rectangle(&pix, 500, 500);
	mlx_put_image_to_window(data.mlx, data.win, img1, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, img2, 100, 100);
	mlx_destroy_image(data.mlx, img1);
	// mlx_put_image_to_window(data.mlx, data.win, img1, 150, 150);
	mlx_key_hook(data.win, stop, &data);
	mlx_loop(data.mlx);
	return (0);
}
