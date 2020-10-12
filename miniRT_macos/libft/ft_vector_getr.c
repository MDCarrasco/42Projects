/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_getr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:47:09 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:10:21 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

t_bool
	ft_vector_getr(t_vector *self, t_ull index, void **value)
{
	if (index >= self->size)
		return (false);
	*value = &(self->raw[self->type_size * index]);
	return (true);
}
