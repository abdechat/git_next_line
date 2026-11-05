/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:11:59 by achancha          #+#    #+#             */
/*   Updated: 2026/11/05 09:28:45 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*add_buffer(char *str, char c)
{
	size_t	len;
	char	*line;

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
