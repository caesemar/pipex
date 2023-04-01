/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:55:01 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/05 03:17:50 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		len;

	len = count * size;
	if (len && (len / size != count))
		return (0);
	str = (char *) malloc(size * count);
	if (!str)
		return (0);
	ft_bzero(str, len);
	return (str);
}
