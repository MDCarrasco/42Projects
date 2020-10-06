/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_ambient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:11:36 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:30:02 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool
	cb_ambient(char **input, t_scene *scene)
{
	if (scene->set & AMB_SET)
		return (false);
	scene->set |= AMB_SET;
	return (expectc(input, 'A')
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &scene->ambient_brightness)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &scene->ambient_color));
}
