/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:39:45 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 19:05:36 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <parser.h>

t_bool
	take_number(char **input, t_ull *out)
{
	t_ull		res;

	res = 0;
	if (!ft_isdigit(**input))
		return (false);
	while (ft_isdigit(**input))
	{
		res = res * 10 + (**input - '0') % 10;
		*input += 1;
	}
	*out = res;
	return (true);
}
