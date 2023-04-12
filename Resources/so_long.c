/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/12 16:17:20 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	so_long(char *map)
// {
// 	if (parser(map))

// 	return ;
// }

void	freemap(char **str)
{
	int	y;

	y = -1;
	while (str[++y])
		free(str[y]);
	free(str[y]);
}

int	main(int c, char **strs)
{
	if (c == 2)
	{
		if (parser(strs[1]))
		{
			ft_printf("valid map!\n");
			// render(strs[1]);
			return (0);
		}
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("Not enough args\n");
	return (0);
}
