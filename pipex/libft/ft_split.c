/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:36:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/31 16:33:21 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**free_split(char **s1, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free (s1[j++]);
	free (s1);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != 0)
		{
			if (k == 0)
			{
				k = 1;
				j++;
			}
			i++;
		}
		k = 0;
		if (s[i] != 0)
			i++;
	}
	return (j);
}

static size_t	word_len(char const *s, char c, size_t *indice)
{
	size_t	i;

	i = 0;
	while (s[*indice] == c)
		*indice = *indice + 1;
	while (s[*indice] != c && s[*indice] != 0)
	{
		*indice = *indice + 1;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char		**s1;
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		tam;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	s1 = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!s1)
		return (NULL);
	while (j < count_words(s, c))
	{
		tam = word_len(s, c, &i);
		k = 0;
		s1[j] = ft_calloc((tam + 1), sizeof(char));
		if (!s1[j])
			return (free_split(s1, j));
		while ((tam) > 0)
			s1[j][k++] = s[i - (tam--)];
		j++;
	}
	return (s1);
}
