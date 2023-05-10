/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:07:26 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/10 23:45:24 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.wall, x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.coin, x, y);
	}
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.e_cl, x, y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.floor, x, y);
	else if (c == 'O')
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.e_op, x, y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.plyr, x, y);
	}
	else if (c == 'X')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->sprite.enemy, x, y);
	}
}

void	render(t_data *data)
{
	t_pos	xy;
	char	*str;

	xy.y = 0;
	mlx_clear_window(data->mlx, data->win);
	while (data->map[xy.y])
	{
		xy.x = 0;
		while (data->map[xy.y][xy.x] && data->map[xy.y][xy.x] != '\n')
		{
			put_img(data, data->map[xy.y][xy.x],
				(SPRITE_SIZE * xy.x), (SPRITE_SIZE * xy.y));
			++xy.x;
		}
		xy.y++;
	}
	str = ft_strdup("moves:");
	mlx_string_put(data->mlx, data->win, 0, 0, 0x00FF00, str);
	free(str);
	str = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->win, 65, 0, 0x00FF00, str);
	free(str);
}

void	move_check(t_data *data, int y, int x)
{
	if (data->map[y][x] == '1' || data->map[y][x] == 'E')
		return ;
	if (data->map[y][x] == 'O')
		exit_prog(data, 1);
	else if (data->map[y][x] == 'X')
		exit_prog(data, 0);
	else
	{
		if (data->map[y][x] == 'C' && --data->coin_count == 0)
				data->map[data->e_pos.y][data->e_pos.x] = 'O';
		data->map[data->p_pos.y][data->p_pos.x] = '0';
		data->map[y][x] = 'P';
		data->p_pos.x = x;
		data->p_pos.y = y;
		data->move_count++;
		render(data);
	}
}

int	key_check(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit_prog(data, 0);
	else if (key == KEY_UP || key == KEY_W)
		move_check(data, data->p_pos.y -1, data->p_pos.x);
	else if (key == KEY_LEFT || key == KEY_A)
		move_check(data, data->p_pos.y, data->p_pos.x -1);
	else if (key == KEY_DOWN || key == KEY_S)
		move_check(data, data->p_pos.y +1, data->p_pos.x);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_check(data, data->p_pos.y, data->p_pos.x +1);
	return (0);
}

void	loop(char *str)
{
	t_data	data;

	init(&data, str);
	mlx_loop_hook(data.mlx, animate, &data);
	mlx_key_hook(data.win, key_check, &data);
	mlx_hook(data.win, ON_DESTROY, 0, exit_prog, &data);
	mlx_loop(data.mlx);
}
