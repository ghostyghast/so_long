/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:09:51 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/10 20:20:15 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*anim_sprite(void **sprite, int frames)
{
	static int	an_frame;
	static int	cur_frame;

	if (cur_frame == frames * (an_frame + 1))
	{
		an_frame++;
		if (!sprite[an_frame])
		{
			an_frame = 0;
			cur_frame = 0;
			return (sprite[an_frame]);
		}
	}
	cur_frame++;
	return (sprite[an_frame]);
}

int	animate(t_data *data)
{
	// data->sprite.coin = anim_sprite(data->sprite.an_c, FRAMES, cur_frame, data);
	data->sprite.player = anim_sprite(data->sprite.an_p, FRAMES);
	render(data);
	return (0);
}

t_pos	direction(t_pos pos)
{
	static int	dir;

	if (dir == 0)
		pos.x -= 1;
	else if
		
}