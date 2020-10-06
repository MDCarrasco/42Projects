/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:02:36 by micarras          #+#    #+#             */
/*   Updated: 2019/10/23 12:08:53 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)str1)[i] == ((unsigned char *)str2)[i] &&
		str1[i] && i < n)
		i++;
	if (i == n)
	{
		return (((unsigned char *)str1)[i - 1] -
			((unsigned char *)str2)[i - 1]);
	}
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
