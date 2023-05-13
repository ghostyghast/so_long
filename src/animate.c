/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:09:51 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/13 19:10:25 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*anim_sprite(void **sprite, int frames, int cur_frame, int an)
{
	static int	an_frame[3];

	if ((cur_frame % frames) == 0)
	{
		an_frame[an]++;
		if (sprite[an_frame[an]] == NULL)
		{
			an_frame[an] = 0;
			return (sprite[an_frame[an]]);
		}
	}
	return (sprite[an_frame[an]]);
}

int	animate(t_data *data)
{
	static int	frame;

	data->sprite.coin = anim_sprite(data->sprite.an_c, 12, frame, 0);
	data->sprite.wall = anim_sprite(data->sprite.an_w, 10, frame, 1);
	data->sprite.plyr = anim_sprite(data->sprite.an_p, 24, frame, 2);
	move_enemies(data->enemies, data->enemy_count, data->map, data);
	render(data);
	frame++;
	if (frame >= FRAMES)
		frame = 0;
	return (0);
}
