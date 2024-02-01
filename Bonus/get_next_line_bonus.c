/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:20:30 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/31 13:55:21 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_test(int fd, char **buff, char **tmp, char **res)
{
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (0);
	*buff = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!*buff)
		return (free(*tmp), *tmp = NULL, 0);
	if (read(fd, *buff, 0) < 0)
		return (free(*tmp), *tmp = NULL, free(*buff), 0);
	return (*res = NULL, 1);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*(s++))
			return (NULL);
	return ((char *)s);
}

static char	*ft_get_line(char *buff, char **tmp, char **res)
{
	int		index;
	char	*srch;
	char	*p;

	srch = ft_strdup(ft_strchr(buff, '\n'));
	if (srch)
	{
		index = ft_strchr(buff, '\n') - buff;
		p = ft_substr(buff, 0, index + 1);
		if (!p)
			return (free(*tmp), *tmp = NULL, free(srch), free(*res), NULL);
		*res = ft_strjoin(*res, p);
		free(p);
		if (!*res)
			return (free(*tmp), *tmp = NULL, free(srch), NULL);
		free(*tmp);
		*tmp = NULL;
		*tmp = ft_strdup(srch + 1);
		return (free(srch), *res);
	}
	*res = ft_strjoin(*res, buff);
	return (free(*tmp), *tmp = NULL, *res);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*tmp;
	char		*res;
	int			b;

	if (!ft_test(fd, &buff, &tmp, &res))
		return (NULL);
	if (tmp != NULL)
	{
		res = ft_get_line(tmp, &tmp, &res);
		if (tmp)
			return (free(buff), res);
	}
	b = read(fd, buff, BUFFER_SIZE);
	while (b > 0)
	{
		buff[b] = '\0';
		res = ft_get_line(buff, &tmp, &res);
		if (tmp)
			return (free(buff), res);
		b = read(fd, buff, BUFFER_SIZE);
	}
	if (res && (ft_strlen(res) == 0))
		return (free(res), free(buff), NULL);
	return (free(buff), res);
}
