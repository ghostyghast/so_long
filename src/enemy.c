/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:04:10 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/09 16:44:17 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_spawner(t_data *data, t_pos p_pos)
{
	if (data->size.y < 4 || data->size.y < 15)
		return ;
	while (data->map[p_pos.x][p_pos.y] != '0')
	{
		
	}
}
