/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/04 17:42:06 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	so_long(char *map)
// {
// 	if (parser(map))

// 	return ;
// }

int	main(int c, char **strs)
{
	if (c == 2)
	{
		if (parser(strs[1]))
		{
			ft_printf("valid map!\n");
			return (0);
		}
		ft_printf("invalid map :( \n");
		return (0);
	}
	ft_printf("Not enough args\n");
	return (0);
}
