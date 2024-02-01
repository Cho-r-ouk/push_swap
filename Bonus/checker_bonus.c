/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:40:25 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/31 16:11:54 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_sorted(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (tab [i + 1] < tab[i])
			return (0);
	return (1);
}

static int	move(int *tab, char *buff, int *size_a, int *size_b)
{
	if ((!ft_memcmp("sa\n", buff) || !ft_memcmp("sa\0", buff)))
		return (s(tab + *size_b), 0);
	else if ((!ft_memcmp("sb\n", buff) || !ft_memcmp("sb\0", buff)))
		return (s(tab), 0);
	else if ((!ft_memcmp("ss\n", buff) || !ft_memcmp("ss\0", buff)))
		return (s(tab + *size_b), s(tab), 0);
	else if ((!ft_memcmp("pa\n", buff) || !ft_memcmp("pa\0", buff)))
		return (pa(tab, *size_b, size_a, size_b), 0);
	else if ((!ft_memcmp("pb\n", buff) || !ft_memcmp("pb\0", buff)))
		return (pb(tab, *size_b + 1, size_b, size_a), 0);
	else if ((!ft_memcmp("ra\n", buff) || !ft_memcmp("ra\0", buff)))
		return (r(tab + *size_b, *size_a), 0);
	else if ((!ft_memcmp("rb\n", buff) || !ft_memcmp("rb\0", buff)))
		return (r(tab, *size_b), 0);
	else if ((!ft_memcmp("rr\n", buff) || !ft_memcmp("rr\0", buff)))
		return (r(tab + *size_b, *size_a), r(tab, *size_b), 0);
	else if ((!ft_memcmp("rra\n", buff) || !ft_memcmp("rra\0", buff)))
		return (rr(tab + *size_b, *size_a), 0);
	else if ((!ft_memcmp("rrb\n", buff) || !ft_memcmp("rrb\0", buff)))
		return (rr(tab, *size_b), 0);
	else if ((!ft_memcmp("rrr\n", buff) || !ft_memcmp("rrr\0", buff)))
		return (rr(tab + *size_b, *size_a), rr(tab, *size_b), 0);
	else
		return (1);
}

static int	apply_moves(int *tab, int size_a, int *size_b)
{
	int		n;
	int		b;
	char	*buff;

	buff = get_next_line(0);
	while (buff)
	{
		b = ft_strlen(buff);
		n = move(tab, buff, &size_a, size_b);
		if (n == 1 || (buff[0] == '\0' || buff[0] == '\n'))
			return (free(buff), write(2, "Error\n", 7), 0);
		free(buff);
		buff = get_next_line(0);
		if (!buff)
			break ;
	}
	return (free(buff), 1);
}

int	main(int ac, char **av)
{
	int	tab_len;
	int	size_b;
	int	*tab;

	size_b = 0;
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
	if (read(0, "", 0) < 0)
		return (free(tab), write (2, "Error\n", 6), 1);
	if (!apply_moves(tab, tab_len, &size_b))
		return (free(tab), 1);
	if (size_b == 0 && is_sorted(tab, tab_len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free(tab), 0);
}
