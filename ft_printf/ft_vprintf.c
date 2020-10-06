/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:32:23 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 12:59:04 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_vprintf(const char *fmt, va_list ap)
{
	return (ft_vprintf_fd(1, fmt, ap));
}

int
	ft_vprintf_fd(int fd, const char *fmt, va_list ap)
{
	char	*str;
	int		res;

	res = ft_vasprintf(&str, fmt, ap);
	if (res == -1)
		write(fd, str, ft_strlen(str));
	else
		write(fd, str, res);
	free(str);
	return (res);
}
