/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:18:10 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 14:20:30 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <color.h>

t_bool
	cb_color(char **input, t_color *color)
{
	t_ull	tmp;

	if (take_number(input, &tmp) && tmp <= 255)
		color->r = (unsigned char)tmp;
	else
		return (false);
	if (expectc(input, ',') && take_number(input, &tmp) && tmp <= 255)
		color->g = (unsigned char)tmp;
	else
		return (false);
	if (expectc(input, ',') && take_number(input, &tmp) && tmp <= 255)
		color->b = (unsigned char)tmp;
	else
		return (false);
	return (true);
}
