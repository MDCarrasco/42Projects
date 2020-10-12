/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_mul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:53:10 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:51:57 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>
#include <libft.h>

t_mat4
	m4_mul(t_mat4 m, t_mat4 mm)
{
	t_mat4	out;
	t_ull	i;
	t_ull	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out.inner[i][j] = m.inner[i][0] * mm.inner[0][j] +
					m.inner[i][1] * mm.inner[1][j] +
					m.inner[i][2] * mm.inner[2][j] +
					m.inner[i][3] * mm.inner[3][j];
			j += 1;
		}
		i += 1;
	}
	return (out);
}
