/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:51:29 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:58:13 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minirt.h>
#include <math.h>

t_bool
	solve_quad(double abc[3], double x[2])
{
	double	discriminant;

	discriminant = pow(abc[1], 2) - 4.0 * abc[0] * abc[2];
	if (discriminant < 0.0)
		return (false);
	else if (discriminant < EPSILON)
	{
		x[0] = -0.5 * abc[1] / abc[0];
		x[1] = x[0];
	}
	else
	{
		x[0] = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
		x[1] = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
	}
	return (true);
}
