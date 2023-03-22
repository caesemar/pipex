/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caesemar <caesemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:12:32 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/06 03:48:07 by caesemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <limits.h>

static int	espacios(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			i++;
			return (-i);
		}
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	j;
	int				signo;

	signo = 1;
	j = 0;
	i = espacios (str);
	if (i < 0)
	{	
		i = -i;
		signo = -1;
	}
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	if (j > LONG_MAX && signo == 1)
		return (-1);
	if (j > LONG_MAX && signo == -1)
		return (0);
	if (signo == -1)
		return (-j);
	return (j);
}
