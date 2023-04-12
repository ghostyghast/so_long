/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:07:57 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/12 16:26:28 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_start(char **map, t_flood *fl, int lw)
{
	fl->s_y = lw;
	fl->s_x = strline(map[0]);
	fl->b_y = 1;
	while (map[fl->b_y])
	{
		fl->b_x = 0;
		while (map[fl->b_y][fl->b_x] != '\n')
		{
			if (map[fl->b_y][fl->b_x] == 'P')
				return ;
			fl->b_x++;
		}
		fl->b_y++;
	}
}

int	valid_char(char c, t_info *info)
{
	if (c == '0' || c == 'C')
		return (1);
	else if (c == 'E')
		info->exit = 1;
	return (0);
}

void	checker(char **map, t_flood *fl, t_pos *p, t_info *info)
{
	fl->b_x = p->x;
	fl->b_y = p->y;
	if (map[fl->b_y][fl->b_x] == 'C')
		info->counter += 1;
	map[fl->b_y][fl->b_x] = 'F';
}

void	floodfill(char **map, t_flood fl, t_pos p, t_info *info)
{
	checker(map, &fl, &p, info);
	if ((fl.b_y > 0) && (valid_char(map[fl.b_y - 1][fl.b_x], info)))
	{
		p.x = fl.b_x;
		p.y = fl.b_y - 1;
		floodfill(map, fl, p, info);
	}
	if (fl.b_y < fl.s_y && valid_char(map[fl.b_y + 1][fl.b_x], info))
	{
		p.x = fl.b_x;
		p.y = fl.b_y + 1;
		floodfill(map, fl, p, info);
	}
	if (fl.b_x < fl.s_x && valid_char(map[fl.b_y][fl.b_x + 1], info))
	{
		p.x = fl.b_x + 1;
		p.y = fl.b_y;
		floodfill(map, fl, p, info);
	}
	if (fl.b_x > 0 && valid_char(map[fl.b_y][fl.b_x - 1], info))
	{
		p.x = fl.b_x - 1;
		p.y = fl.b_y;
		floodfill(map, fl, p, info);
	}
}

int	path_check(char **map, int lw, t_pce pce)
{
	t_flood	fl;
	t_info	info;
	t_pos	p;

	info.coins = pce.c;
	info.counter = 0;
	get_start(map, &fl, lw);
	p.y = fl.b_y;
	p.x = fl.b_x;
	floodfill(map, fl, p, &info);
	if (info.exit == 1 && info.coins == info.counter)
		return (1);
	return (0);
}

// void	printmap(char **map)
// {
// 	t_pos	xy;

// 	xy.y = 0;
// 	while (map[xy.y + 1])
// 	{
// 		ft_printf("%s", map[xy.y]);
// 		xy.y++;
// 	}
// 	ft_printf("%s\n", map[xy.y]);
// }