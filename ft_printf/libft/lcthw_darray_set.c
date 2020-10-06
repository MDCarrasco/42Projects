/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:58:57 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:08:38 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lcthw_darray_set(t_lcthw_darray *array, int i, void *el)
{
	if (array == NULL)
		return ;
	if (i >= array->max)
		return ;
	if (i > array->end)
		array->end = i;
	array->contents[i] = el;
}
