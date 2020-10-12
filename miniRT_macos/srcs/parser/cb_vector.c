/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:15:51 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:33:54 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <scene.h>

t_bool
	cb_vector(char **input, t_vec3d *vec)
{
	return (take_double(input, &vec->x)
			&& expectc(input, ',')
			&& take_double(input, &vec->y)
			&& expectc(input, ',')
			&& take_double(input, &vec->z));
}
