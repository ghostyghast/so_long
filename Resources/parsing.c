/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:09:40 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/03 15:11:44 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	pce_check(char *str)
{
	t_pce	pce;

	while (*str)
	{
		if (*str == 'P')
			pce.p += 1;
		else if (*str == 'C')
			pce.c += 1;
		else if (*str == 'E')
			pce.e += 1;
		str++;
	}
	if ((pce.p != 1) || (pce.p != 1))
		return (0);
	return (1);
}

int	basic_checker(char *str, int fd)
{
	int		len;
	int		req;

	str = get_next_line;
	len = length(str);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		if ((length(str) != len) || !pce_check(str))
			return (0);
		
	}
	return (1);
}

int	path_checker()

int	parser(char *map)
{
	int		fd;
	char	*str;

	fd = open(map, O_RDONLY);
	if (basic_checker(str, fd))
	{
		if()
	}
	return (0);
}
