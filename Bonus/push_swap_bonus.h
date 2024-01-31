/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:54:49 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/30 13:27:07 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

/************ Parse functions ***********/
int		is_sorted(int *tab, int size);
int		is_repeated(int *tab, int size);
int		arg_count(int ac, char **av);
int		*parse(int ac, char **av, int tab_len);
/************ Moves functions ***********/
void	s(int *tab);
void	r(int *tab, int size);
void	rr(int *tab, int size);
void	pa(int *tab, int size, int *s1, int *s2);
void	pb(int *tab, int size, int *s1, int *s2);
/************ Utils functions ***********/
int		find_min(int *t, int size);
int		get_val_index(int *tab, int val, int size);
int		*get_index(int *tab, int size);
char	*get_next_line(int fd);
/************ libft functions ***********/
size_t	ft_strlen(const char *s);
int		ft_atoi(char *s);
void	*ft_memmove(void *dest, const void *src, int n);
int		ft_memcmp(const void *s1, const void *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		ft_wordcount(char const *s, char c);
char	**ft_split(char const *s, char c);
char	**ft_free(char **p, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
/********** testers ************/
//  python3 python_visualizer.py `ruby -e "puts (0..2).to_a.shuffle.join(' ')"`
// python3 tester.py
// bash push_swap_test.sh -b
// ./push_swap $(seq 0 499 | sort -R) | wc -l
// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG