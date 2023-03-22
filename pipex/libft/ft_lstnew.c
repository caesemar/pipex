/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:54:22 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/04 19:31:26 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*cositalinda;

	cositalinda = (t_list *)malloc(sizeof(t_list));
	if (!cositalinda)
		return (0);
	cositalinda->content = content;
	cositalinda->next = NULL;
	return (cositalinda);
}
