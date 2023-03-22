/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:27:47 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/22 00:41:23 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if ((len == 0 && haystack == 0))
		return (0);
	if (*needle == 0)
		return ((char *)&haystack[i]);
	while (haystack[i] != 0 && i < len)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && k < len)
		{
			if (needle[j + 1] == 0 && (haystack[k] == needle[j]))
				return ((char *) &haystack[i]);
			k++;
			j++;
		}
		i++;
	}
	return (0);
}
