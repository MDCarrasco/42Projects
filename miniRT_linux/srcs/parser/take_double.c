/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 13:50:54 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:51:28 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

static void
	take_numberf(char **input, double *out)
{
	while (ft_isdigit(**input))
	{
		*out = *out * 10.0 + (**input - '0') % 10;
		*input += 1;
	}
}

t_bool
	take_double(char **input, double *out)
{
	double		number;
	t_ull		after;
	char		sign;

	number = 0;
	after = 0;
	sign = **input == '-';
	*input += sign;
	if (!ft_isdigit(**input))
		return (false);
	take_numberf(input, &number);
	*input += **input == '.';
	while (ft_isdigit(**input))
	{
		number = number * 10. + (**input - '0') % 10;
		*input += 1;
		after += 1;
	}
	while (after > 0)
	{
		after -= 1;
		number /= 10;
	}
	*out = sign ? -number : number;
	return (true);
}
