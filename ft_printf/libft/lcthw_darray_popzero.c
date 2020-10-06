/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_popzero.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:32:08 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 13:41:04 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lcthw_darray_popzero(t_lcthw_darray *self, int *ans)
{
	while ((((char *)LCTHW_DARRAY_LAST(self))[0] == '0' &&
			(ft_isdigit(((char *)LCTHW_DARRAY_LAST(self) - 1)[0]) ||
			((char *)LCTHW_DARRAY_LAST(self) - 1)[0] == '.')) ||
			((char *)LCTHW_DARRAY_LAST(self))[0] == '.')
	{
		lcthw_darray_pop(self);
		ans--;
	}
}
