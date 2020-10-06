/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_popindex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:41:28 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:50:19 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

/*
** Array::pop_index
** -
** Removes at most _len_ elements starting at _index_.
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/

int
	ft_darray_popindex(t_darray *self, size_t index, size_t len)
{
	const size_t	n = _MIN2(len, self->size - index);

	if (index > self->size)
		return (1);
	ft_memmove(FT_DARRAY_GET(self, index),
				FT_DARRAY_GET(self, index + n),
				FT_DARRAY_OFFSET(self, self->size - n - index));
	self->size -= n;
	return (0);
}

/*
** Array::pop_index w/ function
** -
** Same
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single
** element's contents from its address.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/

int
	ft_darray_popindexf(t_darray *self, size_t index, size_t len,
						void (*del)(void *))
{
	const size_t	n = _MIN2(len, self->size - index);
	size_t			i;

	if (index > self->size)
		return (1);
	i = index - 1;
	while (++i < index + n)
		del(FT_DARRAY_GET(self, i));
	ft_memmove(FT_DARRAY_GET(self, index),
				FT_DARRAY_GET(self, index + n),
				FT_DARRAY_OFFSET(self, self->size - n - index));
	self->size -= n;
	return (0);
}
