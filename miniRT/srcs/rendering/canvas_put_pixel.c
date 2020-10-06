/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:36:05 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 16:50:08 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

void
	canvas_put_pixel(t_canvas *self, unsigned int x, unsigned int y,
			unsigned int color)
{
	t_ull	offset;

	offset = y * self->size_line + x * (self->bits_per_pixel / 8);
	*(unsigned int *)(self->data + offset) = color;
}
