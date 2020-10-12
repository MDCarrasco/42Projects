/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring_fullcon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:53:19 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:11:23 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dstring.h>

t_bool
	dstring_fullcon(t_dstring *output)
{
	output->capacity = 4;
	output->size = 0;
	output->raw = malloc(output->capacity * sizeof(char));
	return (output->raw != NULL);
}
