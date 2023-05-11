/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:15:18 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/11 18:29:16 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	direction(t_pos pos, int dir)
{
	if (dir == 0)
		pos.x -= 1;
	else if (dir == 1)
		pos.y += 1;
	else if (dir == 2)
		pos.x += 1;
	else if (dir == 3)
		pos.y -= 1;
	return (pos);
}

int	check_and_move(char **map, t_pos *pos, int mode, t_data *data)
{
	char			c;
	static int		i;
	t_pos			n_pos;

	n_pos = direction(*pos, i);
	c = map[n_pos.y][n_pos.x];
	if (c != '1' && c != 'E')
	{
		if (c == 'P' && mode == 0)
			exit_prog(data, 0);
		if (mode == 0)
		{
			map[n_pos.y][n_pos.x] = 'X';
			map[pos->y][pos->x] = c;
			*pos = n_pos;
		}
		return (1);
	}
	if (i > 3)
		i = 0;
	else
		i++;
	return (0);
}

void	move_enemies(t_pos *enemies, int enemy_count, char **map, t_data *data)
{
	int			i;
	static int	frame;

	i = -1;
	if (frame == ENEMY_SPEED)
	{
		while (++i < enemy_count)
			check_and_move(map, &enemies[i], 0, data);
		frame = 0;
		return ;
	}
	frame++;
}
