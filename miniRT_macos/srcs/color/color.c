/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:00:11 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:12:16 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_color
	color_fullcon(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	c;

	c = (t_color){b, g, r};
	return (c);
}

static unsigned char
	sat_add(unsigned char a, unsigned char b)
{
	unsigned char	c;

	c = a + b;
	if (c < a)
		c = -1;
	return (c);
}

unsigned int
	color_as_uint(t_color color)
{
	unsigned int	out;

	out = color.r;
	out = (out << 8) + color.g;
	out = (out << 8) + color.b;
	return (out);
}

t_color
	color_add(t_color a, t_color b)
{
	t_color out;

	out = (t_color){sat_add(a.b, b.b), sat_add(a.g, b.g), sat_add(a.r, b.r)};
	return (out);
}

t_color
	color_mul(t_color a, t_color b, double mult)
{
	t_color out;

	out.r = (unsigned char)((double)a.r * (double)b.r * mult / 255.0);
	out.g = (unsigned char)((double)a.g * (double)b.g * mult / 255.0);
	out.b = (unsigned char)((double)a.b * (double)b.b * mult / 255.0);
	return (out);
}
