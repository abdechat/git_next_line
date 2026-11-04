/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:17:09 by achancha          #+#    #+#             */
/*   Updated: 2026/11/04 17:21:15 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_all	var[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (var[fd].ind >= var[fd].re)
		{
			var[fd].ind = 0;
			var[fd].re = read(fd, var[fd].buffer, BUFFER_SIZE);
			if (var[fd].re == -1)
			{
				free(line);
				return (NULL);
			}
			if (var[fd].re == 0)
				return (line);
		}
		line = add_buffer(line, var[fd].buffer[var[fd].ind]);
		if (line == NULL || var[fd].buffer[var[fd].ind++] == '\n')
			return (line);
	}
}
