/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:03:14 by achancha          #+#    #+#             */
/*   Updated: 2026/11/04 17:52:54 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static ssize_t	ind;
	static ssize_t	re;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (ind >= re)
		{
			ind = 0;
			re = read(fd, buffer, BUFFER_SIZE);
			if (re == -1)
				return (ft_free(line));
			if (re == 0)
				return (line);
		}
		line = add_buffer(line, buffer[ind]);
		if (line == NULL || buffer[ind++] == '\n')
			return (line);
	}
}
