/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:27:42 by micarras          #+#    #+#             */
/*   Updated: 2020/01/27 16:10:14 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		multi_fd(t_stock *stock, int fd)
{
	int i;

	i = 0;
	while (fd != 0 && ++i < OPEN_MAX)
		if (stock[i].fd == fd)
			return (i);
	i = 0;
	while (++i < OPEN_MAX)
		if (stock[i].fd == 0)
		{
			stock[i].fd = fd;
			return (i);
		}
	return (-1);
}
