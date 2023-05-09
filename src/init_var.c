/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:46:53 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/09 14:38:42 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pce(t_data *data)
{
	int	x;
	int	y;

	data->coin_count = 0;
	y = 0;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->p_pos.x = x;
				data->p_pos.y = y;
			}
			if (data->map[y][x] == 'C')
				data->coin_count++;
			if (data->map[y][x] == 'E')
			{
				data->e_pos.x = x;
				data->e_pos.y = y;
			}
			x++;
		}
	}
}

void	file_to_img(t_data *data, char *str, void **p)
{
	int		x;
	int		y;
	char	*path;

	x = SPRITE_SIZE;
	y = SPRITE_SIZE;
	path = ft_strjoin("textures/", str);
	*p = mlx_xpm_file_to_image(data->mlx, path, &x, &y);
	free(path);
}

void	textures(t_data *data)
{
	data->sprite.an_c = malloc(sizeof(void *) * (FRAM_COIN + 1));
	data->sprite.an_p = malloc(sizeof(void *) * (FRAM_PLYR + 1));
	data->sprite.an_c[FRAM_COIN] = NULL;
	data->sprite.an_p[FRAM_PLYR] = NULL;
	file_to_img(data, "dogo.xpm", &data->sprite.an_p[0]);
	file_to_img(data, "rayman.xpm", &data->sprite.an_p[1]);
	file_to_img(data, "coin.xpm", &data->sprite.coin);
	// &data->sprite.an_c[0] = file_to_img(data, "coinf");
	// &data->sprite.an_c[1] = file_to_img(data, "coinf");
	// &data->sprite.an_c[2] = file_to_img(data, "coinf");
	file_to_img(data, "eyefloor.xpm", &data->sprite.floor);
	file_to_img(data, "exitclosed.xpm", &data->sprite.e_cl);
	file_to_img(data, "exitopen.xpm", &data->sprite.e_op);
	file_to_img(data, "shitwall.xpm", &data->sprite.wall);
}

void	init(t_data *data, char *str)
{
	data->size.y = 0;
	data->move_count = 0;
	data->map = str_alloc(str, &data->size.y);
	data->size.x = strline(data->map[0]);
	get_pce(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (SPRITE_SIZE * data->size.x),
			(SPRITE_SIZE * data->size.y), "So_long");
	textures(data);
}

// void	printmap(char **map)
// {
// 	t_pos	xy;

// 	xy.y = 0;
// 	while (map[xy.y + 1])
// 	{
// 		ft_printf("%s", map[xy.y]);
// 		xy.y++;
// 	}
// 	ft_printf("%s\n", map[xy.y]);
// }
