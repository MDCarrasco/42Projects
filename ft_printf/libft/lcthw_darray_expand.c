/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_expand.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:48:28 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:01:07 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lcthw_darray_expand(t_lcthw_darray *array)
{
	size_t old_max;

	if (array == NULL)
		return (-1);
	old_max = array->max;
	if (lcthw_darray_resize(array, array->max + array->expand_rate) != 0)
	{
		fprintf(stderr, "Failed to expand array to new size : %d\n",
				array->max + (int)array->expand_rate);
		return (-1);
	}
	ft_memset(array->contents + old_max, 0, array->expand_rate + 1);
	return (0);
}
