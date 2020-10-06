/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:10:34 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 18:58:56 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lcthw_darray	*lcthw_darray_create(size_t element_size, size_t initial_max)
{
	t_lcthw_darray *array;

	if (!(array = (t_lcthw_darray *)malloc(sizeof(t_lcthw_darray))))
		return (NULL);
	array->max = initial_max;
	if (array->max <= 0)
	{
		lcthw_darray_destroy(array);
		return (NULL);
	}
	if (!(array->contents = ft_calloc(initial_max, sizeof(void *))))
	{
		lcthw_darray_destroy(array);
		return (NULL);
	}
	array->end = 0;
	array->element_size = element_size;
	array->expand_rate = LCTHWDA_DEFAULT_EXPAND_RATE;
	return (array);
}
