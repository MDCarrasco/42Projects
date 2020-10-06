/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_overwrite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:44:26 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 23:44:29 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

/*
** Array::overwrite
** -
** Replaces _self_'s contents with _other_'s.
** -
** Will fail, leaving _self_ untouched,
** if the two array's aren't compatible.
** (i.e. if the two types do not have the same lenght)
** -
** Returns a status :
** 0 upon success
** 1 otherwise.
*/

int		ft_darray_overwrite(t_darray *self, const t_darray *other)
{
	if (self->type_size != other->type_size)
		return (1);
	self->size = 0;
	return (ft_darray_reserve(self, other->size)
			|| ft_darray_append(self, other->data, other->size));
}
