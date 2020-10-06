/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:30:47 by micarras          #+#    #+#             */
/*   Updated: 2019/10/28 14:23:42 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getmsize(void *p)
{
	size_t *in;

	in = p;
	if (in != NULL)
	{
		--in;
		return (*in);
	}
	return (-1);
}

void			*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;
	int		malloc_size;

	malloc_size = getmsize(ptr);
	if (size <= (size_t)malloc_size)
		return (ptr);
	newptr = malloc(size);
	ft_memcpy(newptr, ptr, malloc_size);
	free(ptr);
	return (newptr);
}
