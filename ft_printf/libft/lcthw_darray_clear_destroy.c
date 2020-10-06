/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray_clear_destroy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:55:44 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 13:40:02 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_darray_clear_destroy(t_lcthw_darray *array)
{
	if (array == NULL)
		return ;
	lcthw_darray_clear(array);
	lcthw_darray_destroy(array);
	return ;
}
