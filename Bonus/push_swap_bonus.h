/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:54:49 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 18:29:20 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

/************ Moves functions ***********/
void	s(int *tab);
void	r(int *tab, int size);
void	rr(int *tab, int size);
void	pa(int *tab, int size, int *s1, int *s2);
void	pb(int *tab, int size, int *s1, int *s2);
/************ Utils functions ***********/
int		is_repeated(int *tab, int size);
int		arg_count(int ac, char **av);
int		word_count(char const *s, char c);
int		*parse(int ac, char **av, int tab_len);
char	*get_next_line(int fd);
char	**ft_free(char **p, int i);
/************ libft functions ***********/
size_t	ft_strlen(const char *s);
int		ft_atoi(char *s);
int		ft_memcmp(const void *s1, const void *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);

#endif
