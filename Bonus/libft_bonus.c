/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/31 16:23:44 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_memcmp(const void *s1, const void *s2)
{
	size_t	n;

	n = ft_strlen(s2);
	if (n == 0)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && --n)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n)
	{
		while (*(src + i) && --n)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}

int	ft_atoi(char *str)
{
	short		s;
	long		n;
	long		tmp;

	s = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		(str)++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s *= -1;
		(str)++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while ((*str >= '0' && *str <= '9'))
	{
		tmp = n;
		n = n * 10 + *str - '0';
		if (s * n < INT_MIN || s * n > INT_MAX)
			return (0);
		str++;
	}
	return (s * n);
}
