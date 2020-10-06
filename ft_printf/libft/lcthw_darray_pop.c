/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_pop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:59:05 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:03:46 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*lcthw_darray_pop(t_lcthw_darray *array)
{
	void *el;

	el = NULL;
	if (array == NULL)
		return (NULL);
	if (array->end - 1 < 0)
		return (NULL);
	el = lcthw_darray_remove(array, array->end - 1);
	array->end--;
	if (LCTHW_DARRAY_END(array) > (int)array->expand_rate
			&& LCTHW_DARRAY_END(array) % array->expand_rate)
		if (lcthw_darray_contract(array) == -1)
			return (NULL);
	return (el);
}
