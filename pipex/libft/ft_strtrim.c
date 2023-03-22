/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:47:49 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/06 03:50:48 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_last_pos(char const *s1, char const *set)
{	
	int	i;
	int	j;
	int	k;

	i = ft_strlen(s1) - 1;
	while (i != 0)
	{	
		j = 0;
		k = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
				k++;
			j++;
		}
		if (k >= 1)
			i--;
		else
			return (i + 1);
	}
	return (i);
}

static int	get_first_pos(char const *s1, char const *set)
{	
	int	i;
	int	j;
	int	k;

	i = 0;
	while (s1[i] != 0)
	{	
		j = 0;
		k = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
				k++;
			j++;
		}
		if (k >= 1)
			i++;
		else
			return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	if (!s1)
		return (0);
	i = get_last_pos(s1, set) - get_first_pos(s1, set);
	j = 0;
	k = get_first_pos(s1, set);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	s2[i] = 0;
	while (i--)
		s2[j++] = s1[k++];
	return (s2);
}

/*
int main()
{
	char *s1 = "    hiola oue otpal  a      ";
	char *s2 = "oqtp ";

//	s2 [0] = 'o';
//	s2 [1] = 'q';
//	s2 [2] = 't';
	printf("%s\n",ft_strtrim(s1,s2));
	return 0;
}*/