/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:15:00 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/29 15:56:16 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	c;

	i = 0;
	if (dest == 0 && dstsize == 0)
		return (0);
	k = ft_strlen(dest);
	c = ft_strlen(src);
	if (dstsize <= k)
		return (dstsize + c);
	while (src[i] != '\0' && (k + i) < (dstsize - 1))
	{
		dest[k + i] = src[i];
		i++;
	}
	dest[k + i] = '\0';
	return (k + c);
}
