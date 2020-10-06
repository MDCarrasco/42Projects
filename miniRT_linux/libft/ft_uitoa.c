/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:18:25 by micarras          #+#    #+#             */
/*   Updated: 2019/11/12 00:17:57 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n >= 10)
		result = ft_strjoin(ft_uitoa(n / 10), ft_uitoa(n % 10));
	else if (n < 10)
	{
		result[0] = n + '0';
		result[1] = '\0';
	}
	return (result);
}
