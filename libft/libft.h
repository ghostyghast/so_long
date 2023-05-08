/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:15:44 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/08 16:28:41 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1	
# endif

// Get_next_line
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*to_send(char *str);

void	*ft_memcpy(void *dst, void *src, size_t n);

size_t	length(char *str);
int		strcheck(char *s);

// ft_printf
void	writer(const char *str, int *i);
void	ft_putchar(int c, int *i);
void	ft_putnbr(int nb, int *len);
void	ft_putunsigned(unsigned int nb, int *len);
void	ft_puthexa(unsigned int n, int *len);

// libft
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
int		strline(char *str);

#endif