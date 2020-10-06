/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_printdata.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:45:41 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 16:54:25 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"
#include "../ft_printf.h"

void	ft_darray_printdata_int(t_darray *v)
{
	int i;

	i = 0;
	while (i < (int)v->size)
	{
		ft_printf("%d ", ((int*)v->data)[i]);
		i++;
	}
	ft_printf("\n");
}
