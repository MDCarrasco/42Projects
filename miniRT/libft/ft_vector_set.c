/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:49:19 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:13:53 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <libft.h>

t_bool
	ft_vector_set(t_vector *self, t_ull index, void *value)
{
	if (index > self->capacity)
		return (false);
	ft_memcpy(&(self->raw[self->type_size * index]), value, self->type_size);
	return (true);
}
