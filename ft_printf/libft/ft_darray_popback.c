/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_popback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:42:14 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 14:37:35 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

/*
** Array::pop_back
** -
** Removes at most _len_ elements at the end.
** -
** _len_ is the number of elements to be removed.
*/

void
	ft_darray_popback(t_darray *self, size_t len)
{
	self->size -= _MIN2(len, self->size);
}

/*
** Array::pop_back w/ function
** -
** Same as pop_back, but provides a way to avoid leaks by freeing
** contents pointed by the poped elements.
** -
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/

void
	ft_darray_popbackf(t_darray *self, size_t len, void (*del)(void *))
{
	while (self->size > 0 && len > 0)
	{
		self->size--;
		del(FT_DARRAY_END(self));
		len--;
	}
}

void
	ft_darray_popzero(t_darray *self, int *res)
{
	while (((ft_darray_last(self))[0] == '0' &&
		(ft_isdigit((ft_darray_last(self) - 1)[0]) ||
		(ft_darray_last(self) - 1)[0] == '.')) ||
		(ft_darray_last(self))[0] == '.')
	{
		ft_darray_popback(self, 1);
		res--;
	}
}

void
	ft_darray_popzerohex(t_darray *d, int *res)
{
	while (((ft_darray_last(d))[0] == '0' &&
		(ft_ishexdigit((ft_darray_last(d) - 1)[0]) ||
		(ft_darray_last(d) - 1)[0] == '.')) ||
		(ft_darray_last(d))[0] == '.')
	{
		ft_darray_popback(d, 1);
		res--;
	}
}
