/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:06:39 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/21 21:38:42 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *) dst;
	b = (unsigned char *) src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

/*
int main()
{
	char *d = 0;
	char *s = 0;
	printf("memcpy: :%s\n d :%s\n s:%s\n",ft_memcpy(d,s,3), d , s);
}*/