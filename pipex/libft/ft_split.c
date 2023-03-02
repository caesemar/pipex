/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 23:36:08 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/06 03:49:36 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		return (0);
	s1 = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s1)
		return (0);
	while (j < count_words(s, c))
	{
		tam = word_len(s, c, &i);
		k = 0;
		s1[j] = malloc(sizeof(char) * (tam + 1));
		while ((tam) > 0)
			s1[j][k++] = s[i - (tam--)];
		s1[j][k] = 0;
		j++;
	}
	s1[j] = 0;
	return (s1);
}
