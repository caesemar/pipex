/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:17:16 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/01 15:00:35 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	start;
	size_t	i;
	size_t	j;
	size_t	k;

	j = ft_strlen(s1);
	k = ft_strlen(s2);
	i = 0;
	start = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (j + k + 1));
	if (!str)
		return (0);
	while (start < j)
	{
		str[start] = s1[start];
		start++;
	}
	while (i < k)
		str[start++] = s2[i++];
	str[start] = 0;
	return (str);
}
