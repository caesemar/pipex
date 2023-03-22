/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:42:41 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/23 20:45:24 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

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
/*
int main()
{
	char s1[] = "Hola amigo00000000";
	char s2[] = "Hola amigo00000005";
	int i;
	int j;
	
	i=ft_strncmp(s1,s2,8);
	j = strncmp(s1,s2,8);
	printf("%i",j);
	printf("%i",i);
	return 0;
}*/
