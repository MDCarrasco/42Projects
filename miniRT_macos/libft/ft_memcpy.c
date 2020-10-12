/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:56:19 by micarras          #+#    #+#             */
/*   Updated: 2019/11/14 17:03:51 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*src_p;
	unsigned char	*dst_p;

	dst_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	while (n-- > 0)
		*dst_p++ = *src_p++;
	return (dst);
}
