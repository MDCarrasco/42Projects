/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:13:03 by micarras          #+#    #+#             */
/*   Updated: 2019/10/25 14:01:40 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long long n, unsigned int uppercase)
{
	char str[2];
	char digit;

	str[0] = 0;
	str[1] = 0;
	digit = n % 16;
	if (n > 0)
		ft_puthex(n / 16, uppercase);
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
		ft_putstr_fd(str, 1);
	return ;
}
