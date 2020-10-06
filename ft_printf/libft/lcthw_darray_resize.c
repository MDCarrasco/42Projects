/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_resize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:25:43 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:12:02 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** can't use realloc for the first projects so I coded some rudimentary one
** that doesn't work so well but should be enough
*/

int
	lcthw_darray_resize(t_lcthw_darray *array, size_t newsize)
{
	void *contents;

	contents = NULL;
	if (array == NULL)
		return (-1);
	array->max = newsize;
	if (array->max <= 0)
		return (-1);
	if (!(contents = ft_realloc(array->contents, array->max * sizeof(void *))))
		return (-1);
	array->contents = contents;
	return (0);
}
