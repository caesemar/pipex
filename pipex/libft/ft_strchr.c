/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:29:14 by jocasado          #+#    #+#             */
/*   Updated: 2022/09/23 21:16:58 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	d = (unsigned char) c;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == d)
			return ((char *) &s[i]);
		i++;
	}
	if (d == 0)
		return ((char *) &s[i]);
	return (0);
}
