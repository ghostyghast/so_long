/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:07:26 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/24 16:13:30 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	textures(t_data *data)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	data->floor = mlx_xpm_file_to_image(data->mlx, , &w, &h);
	data->wall = mlx_xpm_file_to_image(data->mlx, , &w, &h);
	data->coin = mlx_xpm_file_to_image(data->mlx, , &w, &h);
	data->player = mlx_xpm_file_to_image(data->mlx, , &w, &h);
	data->exit = mlx_xpm_file_to_image(data->mlx, , &w, &h);
}

void	render(char *str)
{
	t_data	data;
	int	lw;

	lw = 0;
	data.map = str_alloc(str, &lw);
	data.mlx = mlx_init();
	
	data.win = mlx_new_window(data.mlx, 1920, 1080, "So_long");
	mlx_loop(data.mlx);
}