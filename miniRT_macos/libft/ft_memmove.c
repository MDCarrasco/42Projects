/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:59:14 by micarras          #+#    #+#             */
/*   Updated: 2019/11/12 14:43:27 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*src_p;
	char		*dst_p;

	dst_p = (char *)dst;
	src_p = (char *)src;
	if (src_p < dst_p)
	{
		while (len--)
			dst_p[len] = src_p[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
