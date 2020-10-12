/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:13:36 by micarras          #+#    #+#             */
/*   Updated: 2019/10/22 13:52:24 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_reve(char *str, int len)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

static int		ft_conv(int n, char *result, size_t i)
{
	int	res;

	while (n != 0)
	{
		res = n % 10;
		result[i++] = res + '0';
		n = n / 10;
	}
	return (i);
}

static char		*ft_casez(char *result, size_t i)
{
	result[i++] = '0';
	result[i] = '\0';
	return (result);
}

void			ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	result[12];
	char	is_negative;

	i = 0;
	is_negative = 0;
	if (n < -2147483647)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n == 0)
		ft_putstr_fd(ft_casez(result, i), fd);
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	i = ft_conv(n, result, i);
	if (is_negative)
		result[i++] = '-';
	result[i] = '\0';
	ft_reve(result, i);
	ft_putstr_fd(result, fd);
}
