/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:40:40 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:20:12 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double
	ft_modf(double num)
{
	long int	intpart;

	intpart = (long int)num;
	return (num - intpart);
}
