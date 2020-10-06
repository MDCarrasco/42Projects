/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:59:51 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:02:00 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*lcthw_darray_get(t_lcthw_darray *array, int i)
{
	if (array == NULL)
		return (NULL);
	if (i >= array->max)
		return (NULL);
	return (array->contents[i]);
}
