/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:32:11 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:45:17 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool
	cb_light(char **input, t_scene *scene)
{
	t_bool		result;
	t_light		light;

	result = (expectc(input, 'l')
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &light.position)
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &light.intensity)
			&& !(light.intensity < 0.0 || light.intensity > 1.0)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &light.color));
	if (result && !ft_vector_push(&scene->lights, &light))
		return (false);
	return (result);
}
