/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:54:49 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 18:29:07 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/************ Parse functions ***********/
int		is_valid(char *s);
int		is_sorted(int *tab, int size);
int		is_repeated(int *tab, int size);
int		arg_count(int ac, char **av);
int		word_count(char const *s, char c);
int		*parse(int ac, char **av, int tab_len);
/************ Moves functions ***********/
void	s(int *tab, char c);
void	r(int *tab, int size, char c);
void	rr(int *tab, int size, char c);
void	p(int *tab, int *s1, int *s2, char c);
/************ Utils functions ***********/
int		get_min(int *t, int size);
int		get_val(int *tab, int val, int size);
int		get_next(int *tab, int size, int p1);
int		*get_index(int *tab, int size);
/************ libft functions ***********/
size_t	ft_strlen(const char *s);
int		ft_atoi(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
void	*ft_memmove(void *dest, const void *src, int n);
char	**ft_split(char const *s, char c);
char	**ft_free(char **p, int i);

#endif
