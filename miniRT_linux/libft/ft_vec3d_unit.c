/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_unit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:49:37 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 15:51:16 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3d.h"

t_vec3d
	v3d_unit(t_vec3d v)
{
	double	magnitude;

	magnitude = v3d_magnitude(v);
	if (magnitude > 0.0)
		return (v3d_divdouble(v3d_fullcon(v.x, v.y, v.z), magnitude));
	return (v3d_fullcon(v.x, v.y, v.z));
}
