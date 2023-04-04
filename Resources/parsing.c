/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:09:40 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/04 18:49:19 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pce_check(char **str)
{
	t_pce	pce;

	pce.y = 0;
	pce.p = 0;
	pce.e = 0;
	pce.c = 0;
	while (str[pce.y])
	{
		pce.x = 0;
		while ((str[pce.y][pce.x] != '\0') && (str[pce.y][pce.x] != '\n'))
		{
			if (str[pce.y][pce.x] == 'P')
				pce.p += 1;
			else if (str[pce.y][pce.x] == 'C')
				pce.c += 1;
			else if (str[pce.y][pce.x] == 'E')
				pce.e += 1;
		pce.x++;
		}
	pce.y++;
	}
	if ((pce.e != 1) || (pce.p != 1) || (pce.c < 1))
		return (0);
	return (1);
}

int	wall_check(char *str)
{
	while (*str && (*str != '\n'))
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	line_check(char **str, int lw)
{
	int	y;
	int	len;

	y = 0;
	len = strline(str[0]);
	if (wall_check(str[0]) && wall_check(str[lw - 1]))
	{
		while (str[y])
		{
			if ((strline(str[y]) != len)
				|| (str[y][0] != '1' || str[y][len - 1] != '1'))
				return (0);
			y++;
		}
		return (1);
	}
	return (0);
}

char	**str_alloc(char *map, int *lw)
{
	char	**str;
	int		fd;
	int		i;

	i = -1;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd))
		*lw += 1;
	close(fd);
	str = ft_calloc(sizeof(char *), (*lw + 1));
	str[*lw] = NULL;
	fd = open(map, O_RDONLY);
	while (++i < *lw)
		str[i] = get_next_line(fd);
	close(fd);
	return (str);
}

int	parser(char *map)
{
	char	**str;
	int		lw;

	lw = 0;
	str = str_alloc(map, &lw);
	if (pce_check(str) && line_check(str, lw))
	{
		// if (path_check(str))
			return (1);
	}
	return (0);
}
