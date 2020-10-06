/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_cons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:45:15 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:00:12 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3d.h"

t_vec3d
	v3d_defaultcon(void)
{
	t_vec3d v;

	v = (t_vec3d){0};
	return (v);
}

t_vec3d
	v3d_singlecon(double x)
{
	t_vec3d v;

	v = (t_vec3d){x, x, x};
	return (v);
}

t_vec3d
	v3d_fullcon(double x, double y, double z)
{
	t_vec3d v;

	v = (t_vec3d){x, y, z};
	return (v);
}
