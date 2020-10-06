/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_pushhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:50:20 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:08:03 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	lcthw_pushhex(unsigned long long n, unsigned int uppercase,
			t_lcthw_darray *a)
{
	char		str[2];
	char		digit;
	static int	count;

	str[0] = 0;
	str[1] = 0;
	digit = n % 16;
	count = 0;
	if (n > 0)
		lcthw_pushhex(n / 16, uppercase, a);
	if (digit < 10)
		str[0] = '0' + digit;
	else
	{
		if (uppercase == 0)
			str[0] = 'a' + digit - 10;
		else
			str[0] = 'A' + digit - 10;
	}
	if (n != 0)
	{
		a->contents[count] = ft_strdup(str);
		a->end++;
		count++;
	}
}
