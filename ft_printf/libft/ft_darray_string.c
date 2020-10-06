/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:53:51 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 16:59:36 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

#define TMP_STRING_APPEND(A,S) ft_darray_append(A, S, ft_strlen(S))

/*
** Array::string
** -
** toString
** description
** -
** _f_ converts an element to a string.
** -
** Returns a string representing the given array.
*/

char	*ft_darray_string(t_darray *self, char *(*f)(void *))
{
	t_darray	res[1];
	void		*iterator;
	char		*tmp;

	*res = NEW_FT_DARRAY(char);
	ft_darray_reserve(self, self->size * 3 + 10);
	TMP_STRING_APPEND(res, "[|");
	iterator = FT_DARRAY_START(self);
	tmp = f(iterator);
	TMP_STRING_APPEND(res, tmp);
	while (FT_DARRAY_HASNEXT(self, iterator))
	{
		TMP_STRING_APPEND(res, ", ");
		tmp = f(iterator);
		TMP_STRING_APPEND(res, tmp);
	}
	ft_darray_append(res, "|]", 3);
	return ((char *)res->data);
}

#undef TMP_STRING_APPEND
