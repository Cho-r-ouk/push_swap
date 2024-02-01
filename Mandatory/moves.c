/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:41 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 12:17:14 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(int *tab, char c)
{
	int	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	r(int *tab, int size, char c)
{
	int	tmp;

	tmp = tab[0];
	ft_memmove(tab, tab + 1, (size - 1) * sizeof(int));
	tab[size - 1] = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(int *tab, int size, char c)
{
	int	tmp;

	tmp = tab[size - 1];
	ft_memmove(tab + 1, tab, (size - 1) * sizeof(int));
	tab[0] = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	p(int *tab, int *s1, int *s2, char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = tab[0];
		ft_memmove(tab, tab + 1, (*s2 - 1) * sizeof(int));
		tab[*s2 - 1] = tmp;
		write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		tmp = tab[*s1];
		ft_memmove(tab + 1, tab, (*s1) * sizeof(int));
		tab[0] = tmp;
		write(1, "pb\n", 3);
	}
	(*s1)++;
	(*s2)--;
}
