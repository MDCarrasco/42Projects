/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:56:45 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 12:57:57 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char
	*pf_update_precision(const char *s, t_modifier *m, va_list dap)
{
	if (*s == '*')
	{
		m->precision = va_arg(dap, unsigned);
		return (s + 1);
	}
	m->precision = 0;
	while (ft_isdigit(*s))
		m->precision = 10 * (m->precision) + *s++ - '0';
	return (s);
}

static const char
	*pf_update_size(const char *s, t_modifier *m, va_list dap)
{
	va_list	temp;
	int		value;

	va_copy(temp, dap);
	if (*s == '*')
	{
		value = va_arg(dap, int);
		m->size = ABS(value);
		if (value < 0)
			m->booleans.n.minus = 1;
		return (++s);
	}
	else
	{
		m->size = 0;
		while (ft_isdigit(*s))
			m->size = 10 * (m->size) + *s++ - '0';
	}
	return (s);
}

static void
	pf_set_length_modifier(char c, char *lm)
{
	if (c == 'h' && *lm == 'h')
		*lm = ft_toupper(c);
	else if (c == 'l' && *lm == 'l')
		*lm = '7';
	else if (*lm == 0)
		*lm = c;
}

static const char
	*pf_match(const char *s, t_modifier *m, va_list dap)
{
	*m = NEW_MODIFIER;
	while (*(++s) != '\0')
	{
		if (*s == '.')
			s = pf_update_precision(s + 1, m, dap) - 1;
		else if (*s == '\'')
			m->quote = 1;
		else if (('1' <= *s && *s <= '9') || *s == '*')
			s = pf_update_size(s, m, dap) - 1;
		else if (is_in(*s, FTPF_SWITCHES) >= 0)
			m->booleans.t[is_in(*s, FTPF_SWITCHES)] = 1;
		else if (is_in(*s, FTPF_LM) >= 0)
			pf_set_length_modifier(*s, &(m->length));
		else if ((m->conversion = *s))
			return (s + 1);
	}
	return (s);
}

int
	ft_vasprintf(char **ret, const char *s, va_list ap)
{
	t_darray	d;
	t_modifier	m;
	va_list		dap;

	va_copy(dap, ap);
	d = NEW_FT_DARRAY(char);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s = pf_match(s, &m, dap);
			if (m.conversion && pf_convert(&m, &d, dap) == -1)
			{
				ft_darray_resize(&d, m.mindex);
				ft_darray_trim(&d);
				*ret = d.data;
				return (-1);
			}
			m.mindex = d.size;
		}
		s = pf_next_specifier(s, &d);
	}
	ft_darray_trim(&d);
	*ret = d.data;
	return (d.size - 1);
}
