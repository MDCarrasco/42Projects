/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:30:26 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 11:43:25 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  All of those functions return the number of bytes written.
*/

int
	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		byte_count;

	va_start(ap, fmt);
	byte_count = ft_vprintf(fmt, ap);
	va_end(ap);
	return (byte_count);
}

/*
** May need this later
*/

int
	ft_printf_fd(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		byte_count;

	va_start(ap, fmt);
	byte_count = ft_vprintf_fd(fd, fmt, ap);
	va_end(ap);
	return (byte_count);
}

/*
** For test purposes
*/

int
	ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list	ap;
	int		byte_count;

	va_start(ap, fmt);
	byte_count = ft_vasprintf(ret, fmt, ap);
	va_end(ap);
	return (byte_count);
}
