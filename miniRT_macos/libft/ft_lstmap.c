/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:44:11 by micarras          #+#    #+#             */
/*   Updated: 2019/10/22 19:12:14 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_lstclear_custom(t_list *head, void (*del)(void *))
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		if (del)
			(*del)(head->content);
		else if (head->content)
			free(head->content);
		free(head);
		head = tmp;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*newnode;
	t_list	*prev;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	head = lst;
	start = NULL;
	prev = NULL;
	while (head)
	{
		if (!(newnode = ft_lstnew(
			(*f)((void *)(head->content)))))
			return (ft_lstclear_custom(start, del));
		if (prev)
			prev->next = newnode;
		prev = newnode;
		head = head->next;
		if (!start)
			start = newnode;
	}
	if (lst != NULL && f != NULL && del != NULL)
		newnode->next = NULL;
	return (start);
}
