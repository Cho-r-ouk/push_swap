/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/31 10:33:55 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (++count);
}

static int	ft_wordlenth(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_free(char **p, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		free(p[j]);
	free(p);
	return (NULL);
}

static char	**ft_conditions(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	if (*s == '\0' || ft_wordcount(s, c) == 0)
		p = (char **)malloc(sizeof (char *));
	else
		p = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		k;
	int		i;

	k = 0;
	i = 0;
	p = ft_conditions(s, c);
	if (p == NULL)
		return (NULL);
	while (s[i] && k < ft_wordcount(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			p[k] = (char *)malloc((1 + ft_wordlenth(s, c, i)) * sizeof(char));
			if (!p[k])
				return (ft_free(p, k));
			ft_strlcpy(p[k++], s + i, ft_wordlenth(s, c, i) + 1);
			i += ft_wordlenth(s, c, i);
		}
	}
	p[k] = NULL;
	return (p);
}
