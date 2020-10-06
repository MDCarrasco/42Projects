/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:37:34 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 14:40:10 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_culturization(t_darray *d, char c)
{
	t_darray	tmp;
	int			i;

	i = 1;
	tmp = NEW_FT_DARRAY(char);
	while (ft_isdigit((ft_darray_last(d))[0]))
	{
		ft_darray_append(&tmp, ft_darray_last(d), 1);
		ft_darray_popback(d, 1);
		if (i % 3 == 0 && ft_isdigit((ft_darray_last(d))[0]))
			ft_darray_append(&tmp, &c, 1);
		i++;
	}
	while (tmp.size > 0)
	{
		ft_darray_append(d, ft_darray_last(&tmp), 1);
		ft_darray_popback(&tmp, 1);
	}
	return (i / 3);
}

int
	pf_itoa_base(t_darray *d, intmax_t number, int base, unsigned char cap)
{
	int					res;
	const char *const	base_str =

	(cap > 0 ? "0123456789ABCDEF" : "0123456789abcdef");
	res = 1;
	if (number <= -base || base <= number)
		res += pf_itoa_base(d, number / base, base, cap);
	ft_darray_append(d, (void *)(base_str + ABS(number % base)), 1);
	return (res);
}

int
	pf_uitoa_base(t_darray *d, uintmax_t number, int base, unsigned char cap)
{
	int					res;
	const char *const	base_str =

	(cap > 0 ? "0123456789ABCDEF" : "0123456789abcdef");
	res = 1;
	if ((uintmax_t)base <= number)
		res += pf_uitoa_base(d, (intmax_t)(number / base), base, cap);
	ft_darray_append(d, (void *)base_str + ((size_t)(number % base)), 1);
	return (res);
}
