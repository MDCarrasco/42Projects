/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:57:22 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 23:57:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

/*
** Array::trim
** -
** Could be called "shrink to fit" as it is in C++.
** This function is meant to be called when no more
** elements are expected to be appended to the array.
** Usually there are extra bytes allocated, to ensure
** a low complexity and few system calls, but this
** functions allocates the minimum number of bytes for
** all elements to fit.
** -
** Returns :
** 0 if the malloc succeeded,
** 1 otherwise.
*/

int		ft_darray_trim(t_darray *self)
{
	ft_darray_append(self, "\0", 1);
	if (self->size < self->max)
		return (ft_darray_resize(self, self->size));
	return (0);
}
