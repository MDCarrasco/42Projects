/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:12:20 by micarras          #+#    #+#             */
/*   Updated: 2019/10/25 16:11:35 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		list->content = NULL;
	else
	{
		if (!(list->content = malloc(sizeof(void *))))
			return (NULL);
		list->content = ft_strdup(content);
	}
	list->next = NULL;
	return (list);
}
