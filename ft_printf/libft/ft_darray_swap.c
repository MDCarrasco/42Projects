/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:56:06 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 17:01:43 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

/*
** Array::_swap
** -
** swaps an array segment with what follows.
** very specific function, not useful for standard cases.
** -
** "   -1415920000"
** -swap(4, 10)->
** "   -0000141592"
** -swap(0, 4)->
** "-0000141592   "
*/

void	ft_exit(const char *const fnc, const char *const str)
{
	ft_putstr_fd("ERROR\tCritical failure in function ", 2);
	ft_putstr_fd((char *)fnc, 2);
	ft_putstr_fd(". The program will exit, reason being : ", 2);
	ft_putstr_fd((char *)str, 2);
	ft_putstr_fd(".\n", 2);
	exit(1);
}

void	*ft_safe_calloc(size_t count, size_t size)
{
	void	*const res = malloc(count * size);

	if (res == NULL)
		ft_exit("ft_safe_calloc", "Out of memory (Malloc failed)");
	ft_bzero(res, count * size);
	return (res);
}

void	ft_darray_swap(t_darray *self, size_t before, size_t after)
{
	char			*tmp;
	const size_t	len = after - before;
	const size_t	m = self->type_size;

	tmp = ft_safe_calloc(len, m);
	ft_memcpy(tmp, self->data + before * m, m * len);
	ft_memmove(self->data + before * m, self->data + after * m,
		(self->size - after) * m);
	ft_memcpy(self->data + (self->size - len) * m, tmp, len * m);
	free(tmp);
}
