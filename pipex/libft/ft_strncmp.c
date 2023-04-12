/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:42:41 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/12 01:00:33 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	while ((i < n) && (s3[i] != '\0' || s4[i] != '\0'))
	{
		if (s3[i] > s4[i])
			return (s3[i] - s4[i]);
		if (s3[i] < s4[i])
			return (s3[i] - s4[i]);
		i++;
	}
	return (0);
}
