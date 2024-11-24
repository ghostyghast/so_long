/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:09:51 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/24 15:14:36 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h> // For usleep
#include <time.h>   // For clock_gettime

#define FPS 120
#define FRAME_TIME (1000000 / FPS) // Microseconds per frame

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

int animate(t_data *data)
{
    static int frame;
    static struct timespec last_time;
    struct timespec current_time;
    long elapsed_time;

    // Get the current time
    clock_gettime(CLOCK_MONOTONIC, &current_time);

    // Calculate the elapsed time since the last frame
    elapsed_time = (current_time.tv_sec - last_time.tv_sec) * 1000000;
    elapsed_time += (current_time.tv_nsec - last_time.tv_nsec) / 1000;

    // If the elapsed time is less than the frame time, sleep for the remaining time
    if (elapsed_time < FRAME_TIME)
        usleep(FRAME_TIME - elapsed_time);

    // Update the last time to the current time
    clock_gettime(CLOCK_MONOTONIC, &last_time);

    data->sprite.coin = anim_sprite(data->sprite.an_c, 1, frame, 0);
    data->sprite.wall = anim_sprite(data->sprite.an_w, 10, frame, 1);
    data->sprite.plyr = anim_sprite(data->sprite.an_p, 24, frame, 2);
    move_enemies(data->enemies, data->enemy_count, data->map, data);
    render(data);
    frame++;
    frame %= FRAMES;
    return (0);
}
