/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:29:18 by micarras          #+#    #+#             */
/*   Updated: 2019/10/22 13:43:17 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	if (lst && *lst && del)
	{
		head = *lst;
		while (head)
		{
			(*del)((void *)head->content);
			next = head->next;
			free(head);
			head = next;
		}
	}
	*lst = NULL;
}
