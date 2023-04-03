/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:43:03 by amaligno          #+#    #+#             */
/*   Updated: 2023/02/27 20:48:23 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	writer(const char *str, int *i);
void	ft_putchar(int c, int *i);
void	ft_putnbr(int nb, int *len);
void	ft_putunsigned(unsigned int nb, int *len);
void	ft_puthexa(unsigned int n, int *len);
#endif