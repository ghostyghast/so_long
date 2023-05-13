/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:46:53 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/13 19:08:39 by amaligno         ###   ########.fr       */
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

void	textures_2(t_data *data)
{
	file_to_img(data, "eye_wall.xpm", &data->sprite.an_w[0]);
	file_to_img(data, "eye_wall2.xpm", &data->sprite.an_w[1]);
	file_to_img(data, "eye_wall3.xpm", &data->sprite.an_w[2]);
	file_to_img(data, "eye_wall4.xpm", &data->sprite.an_w[3]);
	file_to_img(data, "eye_wall5.xpm", &data->sprite.an_w[4]);
	file_to_img(data, "eye_wall6.xpm", &data->sprite.an_w[5]);
	file_to_img(data, "eye_wall7.xpm", &data->sprite.an_w[6]);
	file_to_img(data, "eye_wall8.xpm", &data->sprite.an_w[7]);
	file_to_img(data, "eye_wall9.xpm", &data->sprite.an_w[8]);
	file_to_img(data, "eye_wall10.xpm", &data->sprite.an_w[9]);
	file_to_img(data, "eye_wall11.xpm", &data->sprite.an_w[10]);
	file_to_img(data, "eye_wall12.xpm", &data->sprite.an_w[11]);
}

void	textures(t_data *data)
{
	data->sprite.an_c = malloc(sizeof(void *) * (FRAM_COIN + 1));
	data->sprite.an_p = malloc(sizeof(void *) * (FRAM_PLYR + 1));
	data->sprite.an_w = malloc(sizeof(void *) * (FRAM_WALL + 1));
	data->sprite.an_w[12] = NULL;
	data->sprite.an_c[FRAM_COIN] = NULL;
	data->sprite.an_p[FRAM_PLYR] = NULL;
	file_to_img(data, "dogo1.xpm", &data->sprite.an_p[0]);
	file_to_img(data, "dogo4.xpm", &data->sprite.an_p[1]);
	file_to_img(data, "bone1.xpm", &data->sprite.an_c[0]);
	file_to_img(data, "bone2.xpm", &data->sprite.an_c[1]);
	file_to_img(data, "floor.xpm", &data->sprite.floor);
	file_to_img(data, "exitclosed.xpm", &data->sprite.e_cl);
	file_to_img(data, "exitopen.xpm", &data->sprite.e_op);
	file_to_img(data, "ghost.xpm", &data->sprite.enemy);
	textures_2(data);
}

void	init(t_data *data, char *str)
{
	data->size.y = 0;
	data->move_count = 0;
	data->map = str_alloc(str, &data->size.y);
	data->size.x = strline(data->map[0]);
	get_pce(data);
	enemy_spawncheck(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (SPRITE_SIZE * data->size.x),
			(SPRITE_SIZE * data->size.y), "So_long");
	textures(data);
}
