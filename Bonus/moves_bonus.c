/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:41 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/02 09:43:29 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	s(int *tab, int size)
{
	if (size > 1)
		r(tab, 2);
}

void	r(int *tab, int size)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = tab[0];
	while (++i < size - 1)
		tab[i] = tab[i + 1];
	tab[size - 1] = tmp;
}

void	rr(int *tab, int size)
{
	int	tmp;
	int	i;

	if (size < 1)
		return ;
	i = size;
	tmp = tab[size - 1];
	while (--i > 0)
		tab[i] = tab[i - 1];
	tab[0] = tmp;
}

void	pa(int *tab, int size, int *s1, int *s2)
{
	if (*s2 < 1)
		return ;
	r(tab, size);
	(*s1)++;
	(*s2)--;
}

void	pb(int *tab, int size, int *s1, int *s2)
{
	rr(tab, size);
	(*s1)++;
	(*s2)--;
}
