/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:10 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:18:57 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_ray
	ray_fullcon(t_vec3d origin, t_vec3d direction)
{
	t_ray	r;

	r = (t_ray){origin, direction};
	return (r);
}
