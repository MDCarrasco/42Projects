/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:44:08 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:12:07 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <libft.h>

t_bool
	ft_vector_get(t_vector *self, t_ull index, void *value)
{
	if (index >= self->size)
		return (false);
	ft_memcpy(value, &(self->raw[self->type_size * index]), self->type_size);
	return (true);
}
