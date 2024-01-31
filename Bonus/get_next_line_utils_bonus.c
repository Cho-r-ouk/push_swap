/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:38:40 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/29 12:01:17 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	p = (char *)malloc((n + 1) * sizeof(char));
	if (!p)
		return (NULL);
	return (ft_strlcpy(p, s, n + 1), p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (start > n)
		return (ft_strdup(""));
	if (len > n - start)
		len = n - start;
	p = (char *)malloc((1 + len) * sizeof(char));
	if (!p)
		return (NULL);
	return (ft_strlcpy(p, s + start, len + 1), p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	n1;
	size_t	n2;
	char	*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (p = ft_strdup(s2), p);
	if (!s2)
		return (p = ft_strdup(s1), p);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	p = (char *)malloc((n1 + n2 + 1) * sizeof(char));
	if (!p)
		return (free(s1), NULL);
	ft_strlcpy(p, s1, n1 + 1);
	ft_strlcpy(p + n1, s2, n2 + 1);
	return (free(s1), p);
}
