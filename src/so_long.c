/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/13 19:19:05 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(char **str)
{
	int	y;

	y = -1;
	while (str[++y])
		free(str[y]);
	free(str[y]);
	free(str);
}

int	exit_prog(t_data *data, int i)
{
	if (i == 1)
		ft_printf("You win!! :) :)\n");
	else if (i == 0)
		ft_printf("You lose :(\n");
	freemap(data->map);
	free(data->sprite.an_c);
	free(data->sprite.an_p);
	free(data->sprite.an_w);
	free(data->enemies);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

int	main(int c, char **strs)
{
	if (c == 2)
	{
		if (parser(strs[1]))
		{
			loop(strs[1]);
			return (0);
		}
		ft_printf("Map Error\n");
		return (0);
	}
	ft_printf("Not enough args\n");
	return (0);
}
