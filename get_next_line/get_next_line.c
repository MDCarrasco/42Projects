/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:22:51 by micarras          #+#    #+#             */
/*   Updated: 2020/01/27 16:10:40 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Before end of line
** gets end of line index (returns len of content before return char)
*/

static int	till_eol(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

/*
** 1 - Checks if line contains any return
** 1a - if so, malloc for line with null termination
** 1b - strcpy into previously malloc'ed return line
** 1c - null termination of return line
** 1d - fills stock string with content after return char
** 1e - resets stock string len to content after return char len
** 2 - if not, returns 0, this is the last line
*/

static int	pop_line(t_stock *stock, char **line)
{
	int i;
	int j;
	int	eol;

	if ((eol = till_eol(stock->s, stock->len)) != -1)
	{
		if (!(*line = malloc(eol + 1)))
			return (-1);
		i = -1;
		while (++i < eol)
			(*line)[i] = stock->s[i];
		(*line)[i++] = '\0';
		j = 0;
		while (stock->s[i] && i < stock->len)
			stock->s[j++] = stock->s[i++];
		stock->len = j;
		return (1);
	}
	return (0);
}

/*
** copies with offset
*/

static int	cpy(char *line, char *buff, int offset, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		line[offset + i] = buff[i];
		i++;
	}
	return (i);
}

/*
** 1 - calls read function on stock->fd
** 2 - if eol or eof
** 2a - allocates en0ugh space for the line
** 2b - copies the stock->s into the line
** 2c - copies buffer into the line
** 2d - null terminates the line
** 2e - copies what's left into the buffer after eol
** 2f - returns 0 or 1 depending on the context
** 3 - if line read contains no null or return, recursive call with i_read++
** 4 - copies buffer into the line with old_len
** 5 - returns second ret
*/

static int	retrieve_line(char **line, t_stock *stock, int i_line, int i_read)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		eol;
	int		ret2;

	if ((ret = read(stock->fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	if ((eol = till_eol(buffer, ret)) != -1 || ret != BUFFER_SIZE)
	{
		if (!(*line = malloc(i_read * BUFFER_SIZE + \
				(eol == -1 ? ret : eol) + stock->len + 1)))
			return (-1);
		cpy(*line, stock->s, 0, stock->len);
		i = cpy(*line, buffer, i_read * BUFFER_SIZE + stock->len, \
				(eol == -1 ? ret : eol));
		(*line)[i_read * BUFFER_SIZE + stock->len + i++] = '\0';
		stock->len = cpy(stock->s, &buffer[i], 0, ret - i);
		return (eol != -1 ? 1 : 0);
	}
	if ((ret2 = retrieve_line(line, stock, i_line, i_read + 1)) == -1)
		return (-1);
	cpy(*line, buffer, i_read * BUFFER_SIZE + stock->old_len, ret);
	return (ret2);
}

/*
** 1 - checks for any weird input values
** 2 - calls pop_line function with error check
** 3 - sets fd and does a backup of former line length
** 4 - calls retrieve_line with error check
*/

int			get_next_line(int fd, char **line)
{
	static t_stock	stock;
	int				ret;

	if ((fd < 0 || fd > OPEN_MAX) || !line || BUFFER_SIZE < 1 || \
			read(fd, NULL, 0) == -1)
		return (-1);
	if ((ret = pop_line(&stock, line)) != 0)
		return (ret);
	stock.fd = fd;
	stock.old_len = stock.len;
	if ((ret = retrieve_line(line, &stock, 0, 0)) == -1)
		return (-1);
	return (ret);
}
