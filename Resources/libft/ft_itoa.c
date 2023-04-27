/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:14:11 by amaligno          #+#    #+#             */
/*   Updated: 2023/04/27 14:15:18 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	numlen(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

static char	*alloc(int n)
{
	char	*str;

	str = malloc((numlen(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static void	*itoa(char *str, int n, int full)
{
	int	i;
	int	f;

	if (n < 0)
	{
		i = (n * -1);
		str[0] = '-';
		f = full;
		str[full + 1] = '\0';
	}
	else
	{
		i = n;
		f = (full - 1);
		str[full] = '\0';
	}
	while (i > 9)
	{
		str[f--] = ('0' + (i % 10));
		i /= 10;
	}
	str[f] = (i + '0');
	return (str);
}

static char	*exception(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		full;

	if (n == 0)
	{
		str = exception();
		return (str);
	}
	str = alloc(n);
	if (!str)
		return (NULL);
	full = numlen(n);
	str = itoa(str, n, full);
	return (str);
}

// #include <limits.h>
// int	main(void)
// {
// 	int		f;
// 	char	*s;

// 	f = INT_MIN;
// 	s = ft_itoa(f);
// 	printf("%s", s);
// 	system("leaks a.out");
// }
