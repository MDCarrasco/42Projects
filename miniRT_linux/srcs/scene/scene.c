/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 15:54:40 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:56:41 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_bool
	scene_cast_ray(t_scene *self, const t_ray *ray, t_renderable **hit,
			double *distance)
{
	double			tmp;
	t_renderable	*obj;
	t_ull			i;
	t_bool			found;

	i = 0;
	found = false;
	*distance = NAN;
	while (i < self->objects.size)
	{
		ft_vector_getr(&self->objects, i, (void **)&obj);
		if (obj->ray_intersect(obj, ray, &tmp) && (!found || *distance > tmp))
		{
			*distance = tmp;
			if (hit != NULL)
				*hit = obj;
			found = true;
		}
		i += 1;
	}
	return (found);
}
