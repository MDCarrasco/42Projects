/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_inverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:42:28 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:51:09 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_mat4.h>

t_mat4
	m4_inverse(t_mat4 m)
{
	t_mat4	out;
	t_ull	x;
	t_ull	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			out.inner[x][y] = m.inner[y][x];
			y += 1;
		}
		x += 1;
	}
	return (out);
}
