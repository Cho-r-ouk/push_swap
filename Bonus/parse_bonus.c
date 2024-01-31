/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:48 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/31 09:31:37 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_valid(char *s)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(s))
		return (0);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (ft_strlen(s) == i)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9')
			&& s[i] != ' ' && s[i] != '-' && s[i] != '+')
			return (0);
		if ((s[i] >= '0' && s[i] <= '9')
			&& (s[i + 1] == '+' || s[i + 1] == '-'))
			return (0);
		if ((s[i] == '-' || s[i] == '+') && (!s[i + 1] || s[i + 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	is_repeated(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (tab[i] == tab[j] && i != j)
				return (1);
	}
	return (0);
}

int	arg_count(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (-1);
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			k++;
			j++;
		}
		ft_free(split, j);
		i++;
	}
	return (k);
}

static int	check_zero(char *s)
{
	size_t	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_strlen(s) == i)
		return (1);
	return (0);
}

int	*parse(int ac, char **av, int size)
{
	int		i[3];
	int		*res;
	char	**split;

	i[0] = 0;
	i[2] = -1;
	res = (int *)malloc(size * sizeof(int));
	if (!res)
		return (NULL);
	while (++i[0] < ac)
	{
		split = ft_split(av[i[0]], ' ');
		if (!split)
			return (free(res), NULL);
		i[1] = 0;
		while (split[i[1]])
		{
			res[++i[2]] = ft_atoi(split[i[1]]);
			if (res[i[2]] == 0 && !check_zero(split[i[1]]))
				return (ft_free(split, i[1]), free(res), NULL);
			i[1]++;
		}
		ft_free(split, i[1]);
	}
	return (res);
}
