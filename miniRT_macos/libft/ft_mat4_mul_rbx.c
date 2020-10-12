/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_mul_rbx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:01:04 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:52:14 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>

t_mat4
	m4_mul_rbx(t_mat4 m, t_vec3d v)
{
	t_vec3d			right;
	t_vec3d			up;
	t_vec3d			forward;
	t_vec3d			position;
	t_mat4			out;

	right = m4_right_vec(m);
	up = m4_up_vec(m);
	forward = m4_look_vec(m);
	position = m4_pos(m);
	position = v3d_plusv3d(position, v);
	out = m4_fullcon(right, up, forward, position);
	return (out);
}
