/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:42:00 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:46:57 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3d.h"

t_vec3d
	v3d_minusv3d(const t_vec3d v, const t_vec3d vv)
{
	return (v3d_fullcon(v.x - vv.x, v.y - vv.y, v.z - vv.z));
}
