/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:23:05 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:08:19 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <dstring.h>
#include <parser.h>
#include <scene.h>
#include <stdlib.h>

static t_dstring
	read_to_string(int fd)
{
	int			res;
	char		buffer[1025];
	t_dstring	string;

	res = 0;
	assert(dstring_fullcon(&string), "string allocation failed", true);
	while (res > 0 || string.size == 0)
	{
		buffer[res] = '\0';
		if (dstring_push(&string, buffer) == false)
			panic("string allocation failed", true);
		res = read(fd, buffer, 1024);
		if (res <= 0)
			break ;
	}
	if (res == -1)
	{
		free(string.raw);
		panic("failed to read file", true);
	}
	return (string);
}

t_scene
	parse_from_file(const char *path, t_ull scr_x, t_ull scr_y)
{
	int			fd;
	char		*worker;
	t_dstring	file;
	t_scene		out;

	fd = open(path, O_RDONLY);
	assert(fd != -1, "failed to open file", true);
	file = read_to_string(fd);
	assert(dstring_push(&file, "a"), "string allocation failed", true);
	file.raw[file.size - 1] = '\0';
	worker = file.raw;
	if (cb_scene(&worker, &out, scr_x, scr_y) == false || *worker != '\0')
	{
		free(file.raw);
		panic("unable to parse file", false);
	}
	free(file.raw);
	return (out);
}
