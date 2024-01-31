/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:41 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/29 20:28:08 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	s(int *tab)
{
	r(tab, 2);
}

void	r(int *tab, int size)
{
	int	tmp;

	tmp = tab[0];
	ft_memmove(tab, tab + 1, (size - 1) * sizeof(int));
	tab[size - 1] = tmp;
}

void	rr(int *tab, int size)
{
	int	tmp;

	if (size < 1)
		return ;
	tmp = tab[size - 1];
	ft_memmove(tab + 1, tab, (size - 1) * sizeof(int));
	tab[0] = tmp;
}

void	pa(int *tab, int size, int *s1, int *s2)
{
	int	tmp;

	tmp = tab[0];
	ft_memmove(tab, tab + 1, (size - 1) * sizeof(int));
	tab[size - 1] = tmp;
	(*s1)++;
	(*s2)--;
}

void	pb(int *tab, int size, int *s1, int *s2)
{
	int	tmp;

	tmp = tab[size - 1];
	ft_memmove(tab + 1, tab, (size - 1) * sizeof(int));
	tab[0] = tmp;
	(*s1)++;
	(*s2)--;
}
