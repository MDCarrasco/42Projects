/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:53:29 by micarras          #+#    #+#             */
/*   Updated: 2019/10/23 12:50:36 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		pos;

	i = 0;
	pos = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			pos = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	if (pos == -1)
		return (NULL);
	return ((char *)(str + pos));
}
