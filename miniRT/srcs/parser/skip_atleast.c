/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_atleast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:34:45 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 15:35:43 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <libft.h>

t_bool
	skip_atleast(char **input, char matcher, t_ull times)
{
	t_ull	occurs;

	occurs = 0;
	while ((*input)[occurs] == matcher)
		occurs += 1;
	*input += occurs;
	return (occurs >= times);
}
