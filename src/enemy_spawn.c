/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:04:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/11 18:30:59 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pos(char **map, t_pos pos)
{
	char	c;
	int		i;
	t_pos	n_pos;

	i = -1;
	while (++i < 4)
	{
		n_pos = direction(pos, i);
		c = map[n_pos.y][n_pos.x];
		if (c != '1' && c != 'E')
			return (1);
	}
	return (0);
}

int	enemy_counter(char **map)
{
	int		enemy_count;
	t_pos	pos;

	enemy_count = 0;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x] != '\n' && map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'X')
			{
				if (check_pos(map, pos))
					enemy_count += 1;
				else
					map[pos.y][pos.x] = '0';
			}
		}
	}
	return (enemy_count);
}

void	enemy_position(char **map, t_pos *enemies)
{
	t_pos	pos;
	int		enem;

	enem = -1;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x] != '\n' && map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'X')
				enemies[++enem] = pos;
		}
	}
}

void	printmap(char **map)
{
	while (*map)
	{
		ft_printf("%s", *map);
		map++;
	}
	ft_printf("\n");
}

void	enemy_spawncheck(t_data *data)
{
	data->enemy_count = enemy_counter(data->map);
	data->enemies = malloc(sizeof(t_pos) * data->enemy_count);
	enemy_position(data->map, data->enemies);
}
