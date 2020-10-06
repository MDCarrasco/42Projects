/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:52:13 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 13:38:36 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

/*
** Array::reserve
** -
** When one has an estimation of the number of elements that they will add
** to the array, using reserve will prevent multiple re-allocations,
** and ensure the best complexity.
** Indeed this function makes sure that the array has enough room
** for _size_ elements to be added.
** -
** _size_ is the number of elements that are planned to be added.
** -
** Returns a status :
** 0 in case of success,
** 1 if a re-alloc failed, and leaves the array as-is.
*/

int		ft_darray_reserve(t_darray *self, size_t size)
{
	const size_t	total_size = size + self->size;
	size_t			new_size;

	if (total_size > self->max)
	{
		new_size = (self->max > 0 ? self->max : FT_DARRAY_INITIAL_SIZE);
		while (new_size < total_size)
			new_size *= FT_DARRAY_FACTOR;
		return (ft_darray_resize(self, new_size));
	}
	return (0);
}
