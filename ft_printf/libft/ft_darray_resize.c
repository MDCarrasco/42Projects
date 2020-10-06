/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:53:16 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 16:15:22 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

/*
** Array::_resize
** No subtlety, just resizes the underlying array, no matter the consequences.
** However, in case of a malloc fail, the array is left untouched.
*/

int		ft_darray_resize(t_darray *self, size_t new_size)
{
	void	*tmp;

	tmp = malloc(new_size * self->type_size);
	if (tmp == NULL)
		return (1);
	if (self->size > new_size)
		self->size = new_size;
	ft_memcpy(tmp, self->data, self->size * self->type_size);
	free(self->data);
	self->data = tmp;
	self->max = new_size;
	return (0);
}
