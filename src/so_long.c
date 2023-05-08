/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/08 16:49:20 by amaligno         ###   ########.fr       */
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
	freemap(data->map);
	free(data->sprite.an_c);
	free(data->sprite.an_p);
	mlx_destroy_window(data->mlx, data->win);
	system("leaks so_long");
	exit(0);
	return (0);
}

int	main(int c, char **strs)
{
	if (c == 2)
	{
		if (parser(strs[1]))
		{
			ft_printf("valid map!\n");
			loop(strs[1]);
			return (0);
		}
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("Not enough args\n");
	return (0);
}
