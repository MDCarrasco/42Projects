/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:44:04 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:47:19 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vec3d.h"

t_vec3d
	v3d_plusv3d(t_vec3d v, t_vec3d vv)
{
	return (v3d_fullcon(v.x + vv.x, v.y + vv.y, v.z + vv.z));
}
