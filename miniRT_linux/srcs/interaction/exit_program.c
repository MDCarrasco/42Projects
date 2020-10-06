/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:14:24 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 18:02:51 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <stdlib.h>

void
	exit_program(t_rendering_obj *renderer)
{
	renderer_destroy(renderer);
	exit(0);
}

int
	exit_program_i(t_rendering_obj *renderer)
{
	renderer->window_gone = true;
	exit_program(renderer);
	return (0);
}
