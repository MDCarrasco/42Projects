/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:08:44 by micarras          #+#    #+#             */
/*   Updated: 2019/10/26 20:01:39 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t n)
{
	size_t *result;

	result = malloc(n * sizeof(size_t));
	if (result)
	{
		*result = n;
		++result;
		ft_memset(result, 0, n);
	}
	return (result);
}
