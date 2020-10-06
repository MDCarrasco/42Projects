/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:19:42 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 10:50:48 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	pf_print(t_modifier *m, t_darray *d, va_list ap)
{
	int			i;
	const char	*c = "cspdiuxXnfge";
	void *const t[] = {
	&pf_convert_spec_c, &pf_convert_spec_s, &pf_convert_spec_p,
	&pf_convert_spec_d, &pf_convert_spec_i, &pf_convert_spec_u,
	&pf_convert_spec_x, &pf_convert_spec_cx, &pf_convert_spec_n,
	&pf_convert_spec_f, &pf_convert_spec_g, &pf_convert_spec_e
	};

	i = 0;
	while (c[i] != '\0' && m->conversion != c[i])
		i++;
	if (c[i] != '\0')
		return (((int (*)())t[i])(m, d, ap));
	ft_darray_append(d, &m->conversion, 1);
	m->precision = -1;
	return (1);
}

char
	*pf_next_specifier(const char *s, t_darray *d)
{
	char *p;

	p = (char *)s;
	while (*p != '\0' && *p != '%')
		p++;
	if (p != s)
		ft_darray_append(d, (void *)s, p - s);
	return (p);
}

static int
	pf_precision(t_modifier *m, t_darray *d, va_list ap)
{
	size_t	after;
	int		width;
	int		len;

	width = pf_print(m, d, ap);
	if (width == -1)
		return (-1);
	after = d->size;
	len = width;
	if (len < m->precision && is_in(m->conversion, FTPF_NUMERIC) >= 0)
	{
		while (len < m->precision && ++len)
			ft_darray_append(d, "0", 1);
		ft_darray_swap(d, after - width, after);
	}
	if (m->size < 0 && m->precision == -1)
	{
		m->size = ABS(m->size);
		m->booleans.n.minus = 1;
	}
	return (len);
}

int
	pf_convert(t_modifier *m, t_darray *d, va_list dap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_precision(m, d, dap);
	after = d->size;
	len = after - before;
	if (len <= m->size && width != -1)
	{
		if (m->booleans.n.zero && m->precision <= -1 && !m->booleans.n.minus)
			while (len < m->size && ++len)
				ft_darray_append(d, "0", 1);
		else
			while (len < m->size && ++len)
				ft_darray_append(d, " ", 1);
		if (m->booleans.n.zero && m->precision <= -1 && !m->booleans.n.minus)
			before = after - width;
		if (!m->booleans.n.minus)
			ft_darray_swap(d, before, after);
	}
	return (width);
}
