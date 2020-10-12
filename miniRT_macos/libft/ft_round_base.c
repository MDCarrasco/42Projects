/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:44:18 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:19:16 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int
	ft_round_base(double x, double f, int b)
{
	double		half;
	long int	r;

	r = (long int)(f * 10 + 0.5);
	half = ((double)b) / 2;
	if (r < half)
		return (x);
	else
	{
		x = x + 1;
		while (((long int)x) % (b / 10) != 0)
			x = x + 1;
		return (x);
	}
}
