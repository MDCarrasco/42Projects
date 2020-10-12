/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 09:43:39 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 12:09:20 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>

t_bool
	ft_vector_new(t_vector *self, t_ull type_size)
{
	return (ft_vector_with_capacity(self, type_size, 0));
}
