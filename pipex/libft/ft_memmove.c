/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:24:24 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/28 20:02:39 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*lastsrc;
	char		*lastdst;

	d = (char *) dst;
	s = (const char *)src;
	lastsrc = (char *)s + (n - 1);
	lastdst = (char *)d + (n - 1);
	if (d == s || n == 0)
		return (dst);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
		while (n--)
			*lastdst-- = *lastsrc--;
	return (dst);
}
