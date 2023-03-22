/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:10:01 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/21 21:40:56 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*st;
	size_t			i;

	a = (unsigned char) c;
	st = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (st[i] == a)
			return (&st[i]);
		i++;
	}
	return (0);
}
