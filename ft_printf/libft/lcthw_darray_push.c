/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:56:56 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:05:43 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lcthw_darray_push(t_lcthw_darray *array, void *el)
{
	if (array == NULL)
		return (0);
	array->contents[array->end] = el;
	array->end++;
	if (LCTHW_DARRAY_END(array) >= LCTHW_DARRAY_MAX(array))
	{
		fprintf(stderr, "ARRAY RESIZED\n");
		return (lcthw_darray_expand(array));
	}
	else
		return (-1);
}
