/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:36:08 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/06 20:18:00 by jocasado         ###   ########.fr       */
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

size_t	inside_comma(char const *s, size_t *index, size_t *comma)
{
	if (s[*index] == '\'')
		*comma = *comma + 1;
	if (*comma % 2 == 0)
		return (0);
	else
		return (1);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	comma;

	i = 0;
	j = 0;
	k = 0;
	comma = 0;
	while (s[i] != '\0')
	{
		while (s[i] != 0 && (inside_comma(s, &i, &comma) || s[i] != c))
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
	size_t	comma;

	comma = 0;
	i = 0;
	while (s[*indice] == c)
		*indice = *indice + 1;
	while ((inside_comma(s, indice, &comma) || s[*indice] != c) && s[*indice])
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
