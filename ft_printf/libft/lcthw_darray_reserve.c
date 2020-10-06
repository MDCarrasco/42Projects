/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_reserve.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:57:08 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:09:17 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	lcthw_darray_reserve(t_lcthw_darray *self, size_t size)
{
	const size_t	total_size = size + LCTHW_DARRAY_COUNT(self);
	size_t			new_size;

	if (total_size > (size_t)LCTHW_DARRAY_MAX(self))
	{
		new_size = (LCTHW_DARRAY_MAX(self) > 0 ?
					LCTHW_DARRAY_MAX(self) : LCTHWDA_INITIAL_SIZE);
		while (new_size < total_size)
			new_size *= LCTHWDA_FACTOR;
		return (lcthw_darray_resize(self, new_size));
	}
	return (0);
}
