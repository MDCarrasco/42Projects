/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_substitute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:51:40 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:22:05 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"

/*
** Array::replace
** -
** replace a part of _self_ by _new_
** -
**       |---| <-len
** "echo $USER is cool"
**       |   \----\
** "echo john_smith is cool"
**       ^index
** -
** Returns a status
** 1 in case of failure (malloc)
** 0 otherwise.
*/

int
	ft_darray_substitute(t_darray *self, size_t index, size_t len,
							t_darray *da_new)
{
	return (ft_darray_popindex(self, index, len)
			|| ft_darray_insert(self, da_new->data, da_new->size, index));
}
