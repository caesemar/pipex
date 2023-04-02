/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:07:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/02 21:32:33 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

typedef unsigned int	t_size_t;
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
#endif
