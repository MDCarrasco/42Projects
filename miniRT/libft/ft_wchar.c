/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:51:21 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:14:52 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

size_t
	ft_wstrlen(const wchar_t *wstr)
{
	const wchar_t	*ptr = wstr;

	while (*ptr)
		ptr++;
	return (ptr - wstr);
}

/*
** https://www.cprogramming.com/tutorial/unicode.html
*/

size_t
	ft_widetoa_(char *buff, wint_t w)
{
	if (w < 0x80)
	{
		*buff = (w & 0x7f);
		return (1);
	}
	else if (w < 0x800)
	{
		*(buff++) = ((w >> 6) & 0x1F) | 0xC0;
		*buff = ((w >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else
		return (0);
}

size_t
	ft_widetoa(char *buff, wint_t w)
{
	int	res;

	res = ft_widetoa_(buff, w);
	if (res != 0)
		return (res);
	else if (w < 0x10000)
	{
		*(buff++) = ((w >> 12) & 0xF) | 0xE0;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*buff = ((w >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (w < 0x110000)
	{
		*(buff++) = ((w >> 18) & 0x7) | 0xF0;
		*(buff++) = ((w >> 12) & 0x3F) | 0x80;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*buff = ((w >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}

size_t
	ft_wstrconv(char *buff, const wchar_t *wstr)
{
	size_t	res;

	res = 0;
	while (*wstr != 0)
		res += ft_widetoa(buff + res, (wint_t)*(wstr++));
	return (res);
}

size_t
	ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n)
{
	size_t res;
	size_t tmp;

	res = 0;
	tmp = 0;
	while (*wstr != 0)
	{
		tmp = ft_widetoa(buff + res, (wint_t)*(wstr++));
		if (res + tmp > n)
			break ;
		res += tmp;
	}
	return (res);
}
