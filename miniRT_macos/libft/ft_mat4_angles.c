/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_angles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:28:30 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 15:55:13 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>
#include <math.h>

static t_mat4
	x_angle(double x)
{
	return (m4_fullcon(v3d_right(),
			v3d_fullcon(0.0, cos(x), -sin(x)),
			v3d_fullcon(0.0, sin(x), cos(x)),
			v3d_defaultcon()));
}

static t_mat4
	y_angle(double y)
{
	return (m4_fullcon(v3d_fullcon(cos(y), 0.0, sin(y)),
			v3d_up(),
			v3d_fullcon(-sin(y), 0.0, cos(y)),
			v3d_defaultcon()));
}

static t_mat4
	z_angle(double z)
{
	return (m4_fullcon(v3d_fullcon(cos(z), -sin(z), 0.0),
			v3d_fullcon(sin(z), cos(z), 0.0),
			v3d_forward(),
			v3d_defaultcon()));
}

t_mat4
	m4_angles(double x, double y, double z)
{
	return (m4_mul(m4_mul(x_angle(x), y_angle(y)), z_angle(z)));
}
