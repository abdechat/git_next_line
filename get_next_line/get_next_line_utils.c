/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:20:01 by achancha          #+#    #+#             */
/*   Updated: 2026/11/02 13:37:58 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*add_buffer(char *str, char c)
{
	char	*line;
	size_t	len;

	len = 0;
	if (str)
		while (str[len])
			len++;
	line = malloc(len + 2);
	if (!line)
	{
		free(str);
		return (NULL);
	}
	line[len + 1] = '\0';
	line[len] = c;
	while (len--)
		line[len] = str[len];
	free(str);
	return (line);
}

char	*ft_free(char *line)
{
	free(line);
	return (NULL);
}
