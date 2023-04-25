/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:07:26 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/25 17:32:06 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	textures(t_data *data)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	data->sprites.floor = mlx_xpm_file_to_image(data->mlx,
			"Textures/eyefloor.xpm", &w, &h);
	data->sprites.wall = mlx_xpm_file_to_image(data->mlx,
			"Textures/shitwall.xpm", &w, &h);
	data->sprites.coin = mlx_xpm_file_to_image(data->mlx,
			"Textures/coin.xpm", &w, &h);
	data->sprites.player = mlx_xpm_file_to_image(data->mlx,
			"Textures/exitopen.xpm", &w, &h);
	data->sprites.exit_closed = mlx_xpm_file_to_image(data->mlx,
			"Textures/exitclosed.xpm", &w, &h);
	data->sprites.exit_open = mlx_xpm_file_to_image(data->mlx,
			"Textures/exitopen.xpm", &w, &h);
}

int	key_check(int key, t_data *data)
{
	if (key == KEY_ESC)
	
	else if (key == KEY_UP)

	else if (key == KEY_LEFT)
	
	else if (key == KEY_DOWN)

	else if (key == KEY_RIGHT)

	return (0);
}

void	move(t_data *data, int dir)
{
	
}

void	render(t_data *data)
{
	
}

void	loop(char *str)
{
	t_data	data;
	
	data.size.y = 0;
	data.map = str_alloc(str, &data.size.y);
	data.size.x = strline(data.map[0]);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (64 * data.size.x), (64 * data.size.y), "So_long");
	textures(&data);
	mlx_key_hook(data.mlx, key_check, &data);
	mlx_hook(data.mlx, ON_DESTROY, 0, exit_prog, &data);
	mlx_loop(data.mlx);
}
