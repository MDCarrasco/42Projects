/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:14:52 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 16:36:54 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_darray.h"
#include "libft.h"

/*
** Array::alloc
** -
** Allocates an array and its data.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
** Returns the allocated array,
** or NULL if malloc failed.
*/

t_darray		*ft_darray_alloc(size_t type_size)
{
	t_darray	*res;

	if (!(res = (t_darray *)malloc(sizeof(t_darray))))
		return (NULL);
	ft_bzero(res, sizeof(t_darray));
	res->type_size = type_size;
	return (ft_darray_reserve(res, 1) ? NULL : res);
}
