/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:09:51 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/27 21:43:47 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*anim_sprite(void **sprite, int frames, int cur_frame, t_data *data)
{
	static int	an_frame;

	if (cur_frame == frames * an_frame)
	{
		if (!sprite[an_frame])
			an_frame = 0;
		else
			an_frame++;
	}
	return (sprite[an_frame]);
}

void	animate(t_data *data)
{
	int	frames;
	static int	cur_frame;

	frames = FRAMES;
	
	render(data);
	cur_frame++;
}