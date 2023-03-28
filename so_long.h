/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:25:03 by amaligno          #+#    #+#             */
/*   Updated: 2023/03/28 18:39:53 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

enum
{
	
}

typedef struct s_data
{
	void	*img;
	void	*addr;	
	int		bits;
	int		line;
	int		endian;
}			t_data;

#endif