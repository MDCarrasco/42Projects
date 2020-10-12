/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_divx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:07:35 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:26:15 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3d.h"

t_vec3d
	v3d_divdouble(t_vec3d v, double r)
{
	return (v3d_fullcon(v.x / r, v.y / r, v.z / r));
}

t_vec3d
	v3d_divv3d(t_vec3d v, t_vec3d vv)
{
	return (v3d_fullcon(v.x / vv.x, v.y / vv.y, v.z / vv.z));
}
