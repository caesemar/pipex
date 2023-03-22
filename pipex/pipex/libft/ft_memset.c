/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:42:20 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/21 18:35:01 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *) b;
	while (i != len)
	{
		a[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char*	a;
	char	b[9] = "holaqtal";

	a = ft_memset (b, 65, 8);
	printf("%s", b);
	return (0);
}*/