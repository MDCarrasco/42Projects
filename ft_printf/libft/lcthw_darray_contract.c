/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_contract.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:51:45 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 18:56:50 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lcthw_darray_contract(t_lcthw_darray *array)
{
	int new_size;

	new_size = 0;
	if (array == NULL)
		return (-1);
	new_size = array->end < (int)array->expand_rate ?
		(int)array->expand_rate : array->end;
	return (lcthw_darray_resize(array, new_size + 1));
}
