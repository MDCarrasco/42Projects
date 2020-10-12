/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:46:37 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:09:53 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <stdlib.h>

void
	ft_vector_destroy(t_vector *self)
{
	free(self->raw);
	self->raw = NULL;
	self->capacity = 0;
	self->size = 0;
	self->type_size = 0;
}
