/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:41:04 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 12:23:52 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tree(int *tab)
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

static void	push_b(int *mat, int size, int *size_a, int *size_b)
{
	int	p0;
	int	p1;
	int	p2;

	p0 = -1;
	p1 = size / 3;
	p2 = size / 6;
	while (*size_a > 3)
	{
		if (mat[*size_b] < p1)
			p(mat, size_b, size_a, 'b');
		else if (get_next(mat + *size_b, *size_a, p1) > (*size_a / 2))
			rr(mat + *size_b, *size_a, 'a');
		else if (get_next(mat + *size_b, *size_a, p1) <= (*size_a / 2))
			r(mat + *size_b, *size_a, 'a');
		if (*size_b > 1 && mat[0] > p0 && mat[0] < p2)
			r(mat, *size_b, 'b');
		if (*size_a > 3 && *size_b == p1)
		{
			p0 = p1;
			p1 += *size_a / 3;
			p2 = *size_a / 6 + p0;
		}
	}
	sort_tree(mat + *size_b);
}

static void	push_a(int *mat, int size, int size_a, int size_b)
{
	int	big_index;

	big_index = mat[size - 1];
	while (!(is_sorted(mat, size) && size_b == 0))
	{
		while (size_b && mat[0] != mat[size_b] - 1)
		{
			if (mat[size - 1] < mat[0] || mat[size - 1] == big_index)
			{
				p(mat, &size_a, &size_b, 'a');
				r(mat + size_b, size_a, 'a');
			}
			else if (size_b
				&& (get_val(mat, mat[size_b] - 1, size_b) > (size_b / 2)))
				rr(mat, size_b, 'b');
			else if (size_b
				&& (get_val(mat, mat[size_b] - 1, size_b) <= (size_b / 2)))
				r(mat, size_b, 'b');
		}
		while (size_b && mat[0] == mat[size_b] - 1)
			p(mat, &size_a, &size_b, 'a');
		while (mat[size - 1] == mat[size_b] - 1)
			rr(mat + size_b, size_a, 'a');
	}
}

static void	sort(int *tab, int size)
{
	int	*mat;
	int	size_b;
	int	size_a;

	size_b = 0;
	size_a = size;
	if (size == 1 || is_sorted(tab, size))
		return ;
	else if (size == 2)
		s(tab, 'a');
	else if (size == 3)
		sort_tree(tab);
	else
	{
		mat = get_index(tab, size);
		if (!mat)
			exit(write (2, "Error\n", 6));
		push_b(mat, size, &size_a, &size_b);
		push_a(mat, size, size_a, size_b);
		free(mat);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	tab_len;
	int	*tab;

	i = 0;
	if (ac == 1)
		return (0);
	tab_len = arg_count(ac, av);
	if (tab_len == -1)
		return (write (2, "Error\n", 6), 1);
	tab = parse(ac, av, tab_len);
	if (!tab)
		return (write (2, "Error\n", 6), 1);
	if (is_repeated(tab, tab_len))
		return (free(tab), write (2, "Error\n", 6), 1);
	sort(tab, tab_len);
	return (free(tab), 0);
}
