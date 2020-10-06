/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:48:23 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:12:49 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <libft.h>

t_bool
	ft_vector_push(t_vector *self, void *value)
{
	t_ull	min_capacity;

	min_capacity = self->capacity ? self->capacity : 1;
	if (self->size >= self->capacity)
		if (!ft_vector_resize(self, min_capacity * 2))
			return (false);
	ft_memcpy(&self->raw[self->size * self->type_size],
			value, self->type_size);
	self->size += 1;
	return (true);
}
