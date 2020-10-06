/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_with_capacity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:49:47 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:11:21 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stdlib.h>
#include <stdio.h>

t_bool
	ft_vector_with_capacity(t_vector *self, t_ull type_size, t_ull capacity)
{
	if (capacity > 0)
		self->raw = malloc(type_size * capacity);
	else
		self->raw = NULL;
	if (capacity > 0 && self->raw == NULL)
		return (false);
	self->capacity = capacity;
	self->size = 0;
	self->type_size = type_size;
	return (true);
}
