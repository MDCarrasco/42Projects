/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:47:54 by micarras          #+#    #+#             */
/*   Updated: 2019/11/13 23:48:24 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_darray.h"

/*
** Array::release
** -
** If one initialised the array with ft_darray_alloc, they are advised
** to use ft_darray_release to free it.
** Both the underlying data and the array will be freed.
** -
** _ptr_ is the address of a pointer to an array,
** and will be set to NULL to prevent further uses attempts.
*/

void	ft_darray_release(t_darray **ptr)
{
	ft_darray_clear(*ptr);
	free(*ptr);
	*ptr = NULL;
}
