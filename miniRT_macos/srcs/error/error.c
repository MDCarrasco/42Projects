/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:14:31 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:04:06 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>

void
	assert(t_bool condition, const char *message, t_bool include_errno)
{
	if (condition == false)
		panic(message, include_errno);
}

void
	panic(const char *message, t_bool include_errno)
{
	ft_putstr_fd("Error\n", 2);
	if (include_errno)
		perror(message);
	else
	{
		ft_putstr_fd((char *)message, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(1);
}
