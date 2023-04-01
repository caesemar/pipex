/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:03:16 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/23 21:03:37 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	d;

	d = (unsigned char) c;
	str = (char *) s;
	i = ft_strlen(s);
	if (d == 0)
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == d)
			return (&str[i]);
		i--;
	}
	return (0);
}
