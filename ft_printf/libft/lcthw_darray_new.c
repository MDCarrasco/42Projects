/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:03:55 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 19:02:37 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*lcthw_darray_new(t_lcthw_darray *array)
{
	if (array == NULL)
		return (NULL);
	if (array->element_size <= 0)
		return (NULL);
	return (ft_calloc(1, array->element_size));
}
