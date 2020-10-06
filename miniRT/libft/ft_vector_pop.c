/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:47:44 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:10:38 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

t_bool
	ft_vector_pop(t_vector *self, void *output)
{
	t_bool	result;

	if (self->size == 0)
		return (false);
	result = ft_vector_get(self, self->size - 1, output);
	if (result)
		self->size -= 1;
	return (result);
}
