/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:23:21 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 18:48:31 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lcthw_darray_clear(t_lcthw_darray *array)
{
	int		i;

	i = -1;
	if (array == NULL)
		return ;
	if (array->element_size > 0)
		while (++i < array->max)
			if (array->contents[i] != NULL)
				free(array->contents[i]);
}
