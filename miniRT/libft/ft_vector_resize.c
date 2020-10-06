/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:48:49 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:13:23 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <libft.h>
#include <stdlib.h>

t_bool
	ft_vector_resize(t_vector *self, t_ull capacity)
{
	void	*new;

	if (capacity <= self->capacity)
		return (false);
	new = malloc(self->type_size * capacity);
	if (new == NULL)
		return (false);
	if (self->raw == NULL)
		self->raw = new;
	else
	{
		ft_memcpy(new, self->raw, self->size * self->type_size);
		free(self->raw);
		self->raw = new;
	}
	self->capacity = capacity;
	return (true);
}
