/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_trim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:28:19 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:09:46 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	lcthw_darray_trim(t_lcthw_darray *self)
{
	lcthw_darray_push(self, "\0");
	if (LCTHW_DARRAY_END(self) < LCTHW_DARRAY_MAX(self))
		return (lcthw_darray_resize(self, LCTHW_DARRAY_END(self)));
	return (0);
}
