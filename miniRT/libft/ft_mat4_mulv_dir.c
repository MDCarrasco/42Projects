/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_mulv_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:02:59 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 10:23:07 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>

t_vec3d
	m4_mulv_dir(t_mat4 m, t_vec3d dir)
{
	double	x;
	double	y;
	double	z;

	x = dir.x * m.inner[0][0] + dir.y * m.inner[1][0]
			+ dir.z * m.inner[2][0];
	y = dir.x * m.inner[0][1] + dir.y * m.inner[1][1]
			+ dir.z * m.inner[2][1];
	z = dir.x * m.inner[0][2] + dir.y * m.inner[1][2]
			+ dir.z * m.inner[2][2];
	return (v3d_fullcon(x, y, z));
}
