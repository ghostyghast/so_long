/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:05:13 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/26 19:16:34 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	len;

	len = strline(s1) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len);
	return (str);
}
