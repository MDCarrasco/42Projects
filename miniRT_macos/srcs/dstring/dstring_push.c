/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:54:28 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 19:15:25 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dstring.h>
#include <libft.h>
#include <stdlib.h>

t_bool
	dstring_push(t_dstring *self, const char *str)
{
	t_ull		length;
	char		*new;

	length = ft_strlen(str);
	while ((self->size + length) >= self->capacity)
		self->capacity *= 2;
	new = malloc(self->capacity * sizeof(char));
	if (new == NULL)
	{
		free(self->raw);
		return (false);
	}
	ft_memcpy(new, self->raw, self->size);
	ft_memcpy(new + self->size, str, length);
	free(self->raw);
	self->size += length;
	self->raw = new;
	return (true);
}
