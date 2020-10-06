/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_remove.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:01:23 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:06:14 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*lcthw_darray_remove(t_lcthw_darray *array, int i)
{
	void *el;

	if (array == NULL)
		return (NULL);
	el = array->contents[i];
	array->contents[i] = NULL;
	return (el);
}
