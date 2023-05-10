/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:04:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/10 20:06:51 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_amount(char **map)
{
	int	enemy_count;
	int	x;

	enemy_count = 0;
	while (++map)
	{
		x = 0;
		while (*map[x] != '\n' && *map[x])
		{
			if (*map == 'X')
				enemy_count += 1;
		}
	}
	return (enemy_count);
}

void	enemy_position(char **map, t_pos **enems)
{
	t_pos	pos;
	int		enem;

	enem = -1;
	pos.y = -1;
	while (map[--pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x] != '\n' && map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'X' && enems[++enem])
				*enems[enem] = pos;
		}
	}
}

void	enemy_spawncheck(t_data *data, t_pos p_pos)
{
	int	enemy;

	enemy = enemy_amount(data->map);
	data->enems = (t_pos *)malloc(sizeof(t_pos) * (enemy + 1));
	data->enems[enemy] = NULL;
	enemy_position(data->map, &data->enems);
}

t_pos	enemy_move(char **map, t_pos pos)
{
	static int	frame;
	if ()
	{
		
	}
}