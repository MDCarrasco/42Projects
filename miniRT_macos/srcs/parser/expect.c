/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:19:40 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:57:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <libft.h>

t_bool
	expects(char **input, const char *expected)
{
	const t_ull		length = ft_strlen(expected);
	const t_bool	result = ft_strncmp(*input, expected, length) == 0;

	if (result)
		*input += length;
	return (result);
}

t_bool
	expectc(char **input, char expected)
{
	const t_bool result = **input == expected;

	*input += result;
	return (result);
}
