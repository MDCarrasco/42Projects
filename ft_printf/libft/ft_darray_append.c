/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:42:54 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 16:40:51 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

/*
** Array::apppend
** -
** Could be called "add all" like in Java.
** Adds _data_len_ elements to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _data_len_ should be the number of elements stored in _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int		ft_darray_append(t_darray *self, const void *data, size_t data_len)
{
	if (ft_darray_reserve(self, data_len))
		return (1);
	ft_memcpy(FT_DARRAY_END(self), data, FT_DARRAY_OFFSET(self, data_len));
	self->size += data_len;
	return (0);
}

/*
** Array::apppend_free
** -
** Could be called "add all" like in Java.
** Adds _data_len_ elements to _self_. then free _data_
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _data_len_ should be the number of elements stored in _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int		ft_darray_append_free(t_darray *self, void *data, size_t data_len)
{
	if (ft_darray_reserve(self, data_len))
		return (1);
	ft_memcpy(FT_DARRAY_END(self), data, FT_DARRAY_OFFSET(self, data_len));
	self->size += data_len;
	free(data);
	return (0);
}

/*
** Array::insert
** -
** Adds _data_len_ elements at index _index_ to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _data_len_ should be the number of elements stored in _data_.
** _index_ is the future index of the first element of _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed or if the index isn't valid.
*/

int		ft_darray_insert(
				t_darray *self, void const *data, size_t data_len, size_t index)
{
	if (self->size < index || ft_darray_reserve(self, data_len))
		return (1);
	ft_memmove(FT_DARRAY_GET(self, index + data_len),
				FT_DARRAY_GET(self, index),
				FT_DARRAY_OFFSET(self, self->size - index));
	ft_memcpy(FT_DARRAY_GET(self, index),
				data,
				FT_DARRAY_OFFSET(self, data_len));
	self->size += data_len;
	return (0);
}

/*
** Array::apppend_char
** -
** Could be called "add all" like in Java.
** Adds 1 elements to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type char
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int		ft_darray_append_char(t_darray *self, char data)
{
	if (ft_darray_reserve(self, 1))
		return (1);
	ft_memcpy(FT_DARRAY_END(self), &data, FT_DARRAY_OFFSET(self, 1));
	self->size += 1;
	return (0);
}
