/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:07 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/30 13:39:50 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (tab [i + 1] < tab[i])
			return (0);
	return (1);
}

void	sort_tree(int *tab)
{
	if ((tab[0] > tab[1] && tab[1] > tab[2])
		|| (tab[1] > tab[2] && tab[2] > tab[0])
		|| (tab[2] > tab[0] && tab[0] > tab[1]))
		s(tab, 'a');
	if (tab[0] > tab[2] && tab[2] > tab[1])
		r(tab, 3, 'a');
	if (tab[1] > tab[0] && tab[0] > tab[2])
		rr(tab, 3, 'a');
}

void	sort_four(int *tab)
{
	int	i;
	int	m;

	i = get_min(tab, 4);
	m = tab[i];
	if (i == 1)
		s(tab, 'a');
	if (i < 2)
		while (m != tab[0])
			r(tab, 4, 'a');
	else
		while (m != tab[0])
			rr(tab, 4, 'a');
	if (!is_sorted(tab, 4))
	{
		write(1, "pb\n", 3);
		sort_tree(&tab[1]);
		write(1, "pa\n", 3);
	}
}

void	sort_five(int *tab)
{
	int	i;
	int	m;

	i = get_min(tab, 5);
	m = tab[i];
	if (i == 1)
		s(tab, 'a');
	if (i < 2)
		while (m != tab[0])
			r(tab, 5, 'a');
	else
		while (m != tab[0])
			rr(tab, 5, 'a');
	if (!is_sorted(tab, 5))
	{
		write(1, "pb\n", 3);
		sort_four(&tab[1]);
		write(1, "pa\n", 3);
	}
}
