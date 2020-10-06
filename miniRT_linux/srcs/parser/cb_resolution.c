/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:40:26 by micarras          #+#    #+#             */
/*   Updated: 2020/06/12 09:32:43 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool
	cb_resolution(char **input, t_scene *scene)
{
	t_bool	result;

	if (scene->set & RES_SET)
		return (false);
	result = (expectc(input, 'R')
			&& skip_atleast(input, ' ', 1)
			&& take_number(input, &(scene->resolution[0]))
			&& scene->resolution[0] > 0
			&& skip_atleast(input, ' ', 1)
			&& take_number(input, &(scene->resolution[1]))
			&& scene->resolution[1] > 0);
	if (result)
		scene->set |= RES_SET;
	return (result);
}
