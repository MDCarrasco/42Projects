/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:07:46 by micarras          #+#    #+#             */
/*   Updated: 2019/10/28 15:23:36 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		fprintf(stderr, "The string is empty !!!\n");
		return ;
	}
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
