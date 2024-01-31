/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:54:49 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/30 20:44:44 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/************ Parse functions ***********/
int		is_sorted(int *tab, int size);
int		is_repeated(int *tab, int size);
int		arg_count(int ac, char **av);
int		*parse(int ac, char **av, int tab_len);
/************ sort functions ************/
void	sort_tree(int *tab);
void	sort_four(int *tab);
void	sort_five(int *tab);
/************ Moves functions ***********/
void	s(int *tab, char c);
void	r(int *tab, int size, char c);
void	rr(int *tab, int size, char c);
void	p(int *tab, int *s1, int *s2, char c);
/************ Utils functions ***********/
int		get_min(int *t, int size);
// int find_max(int *t, int size);
int		*get_index(int *tab, int size);
int		get_val(int *tab, int val, int size);
/************ libft functions ***********/
size_t	ft_strlen(const char *s);
int		ft_atoi(char *s);
void	*ft_memmove(void *dest, const void *src, int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_wordcount(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_free(char **p, int i);

#endif
