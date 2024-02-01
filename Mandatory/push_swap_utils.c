/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:54 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 12:18:30 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(int *t, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = t[0];
	index = 0;
	while (++i < size)
	{
		if (min > t[i])
		{
			min = t[i];
			index = i;
		}
	}
	return (index);
}

int	*get_index(int *tab, int size)
{
	int	i;
	int	j;
	int	index;
	int	tmp;
	int	*mat;

	index = 0;
	mat = (int *)malloc(size * sizeof(int ));
	if (!mat)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		tmp = tab[i];
		j = -1;
		while (++j < size)
			if (tmp > tab[j])
				index++;
		mat[i] = index;
		index = 0;
	}
	return (mat);
}

int	get_val(int *tab, int val, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] == val)
			return (i);
	return (i);
}

int	get_next(int *tab, int size, int p1)
{
	int	i;
	int	index1;
	int	index2;

	i = -1;
	while (++i < size)
		if (tab[i] < p1)
			break ;
	index1 = i;
	while (--size >= 0)
		if (tab[size] < p1)
			break ;
	index2 = size;
	if (index1 < index2)
		return (index1);
	return (index2);
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
