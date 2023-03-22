/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:56:15 by jocasado          #+#    #+#             */
/*   Updated: 2023/03/02 13:46:12 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	if (start > s_len)
		len = 0;
	if (s_len - start < len)
		len = s_len - start;
	s1 = (char *)malloc(sizeof(char) * (len +1));
	if (!s1)
		return (0);
	while (i < len)
	{
		if (start < s_len)
			s1[i] = (char) s[i + start];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
