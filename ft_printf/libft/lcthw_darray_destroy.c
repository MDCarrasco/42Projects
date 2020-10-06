/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:54:10 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 18:59:39 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lcthw_darray_destroy(t_lcthw_darray *array)
{
	if (array)
	{
		if (array->contents)
			free(array->contents);
		free(array);
	}
	return ;
}
