/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:43:20 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 23:43:22 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_darray.h"

/*
** Array::clear
** -
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/

void	ft_darray_clear(t_darray *self)
{
	if (self->max > 0)
	{
		free(self->data);
		self->size = 0;
		self->max = 0;
	}
}
