/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spawn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <antoinemalignon@yahoo.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:04:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/11 00:50:20 by amaligno         ###   ########.fr       */
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

void	enemy_position(char **map, t_pos **enemies)
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
			if (map[pos.y][pos.x] == 'X' && enemies[++enem])
				*enemies[enem] = pos;
		}
	}
}

void	enemy_spawncheck(t_data *data)
{
	
	enemy = 0;
}