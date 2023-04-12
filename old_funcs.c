#include "so_long.h"

void	rectangle(t_pix *img, int *xs, int *ys)
{
	int	y;
	int	x;

	x = -1;
	while (++x < xs[0])
	{
		y = -1;
		while (++y < ys[0])
		{
			if ((x >= 10 || x <= 40) && (y <= 10 || y >= 40))
				put_pixel(img, (x + xs[1]), (y + ys[1]), 0xFF00FF00);
			else
				put_pixel(img, (x + xs[1]), (y + ys[1]), 0x0000FF);
		}
	}
}

void	square(t_pix *img, int *xs, int *ys)
{
	int	y;
	int	x;

	x = -1;
	while (++x < xs[0])
	{
		y = -1;
		while (++y < ys[0])
			put_pixel(img, (x + xs[1]), (y + ys[1]), 0x000000FF);
	}
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->line,
			&img->endian);
	dst = img->addr + (y * img->line + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}