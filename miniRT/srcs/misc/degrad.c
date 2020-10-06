/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:52:36 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:38:55 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double
	deg(double radians)
{
	return (radians * (180 / M_PI));
}

double
	rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
