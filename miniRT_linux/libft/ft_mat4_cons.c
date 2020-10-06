/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_cons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 23:23:51 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:50:28 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>

t_mat4
	m4_defaultcon(void)
{
	t_vec3d	zeroed;

	zeroed = v3d_defaultcon();
	return (m4_fullcon(zeroed, zeroed, zeroed, zeroed));
}

t_mat4
	m4_fullcon(t_vec3d right, t_vec3d up, t_vec3d look, t_vec3d pos)
{
	t_mat4	out;

	out.inner[0][0] = right.x;
	out.inner[0][1] = right.y;
	out.inner[0][2] = right.z;
	out.inner[1][0] = up.x;
	out.inner[1][1] = up.y;
	out.inner[1][2] = up.z;
	out.inner[2][0] = look.x;
	out.inner[2][1] = look.y;
	out.inner[2][2] = look.z;
	out.inner[3][0] = pos.x;
	out.inner[3][1] = pos.y;
	out.inner[3][2] = pos.z;
	out.inner[0][3] = 0.0;
	out.inner[1][3] = 0.0;
	out.inner[2][3] = 0.0;
	out.inner[3][3] = 1.0;
	return (out);
}
