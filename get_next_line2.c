/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:37:44 by achancha          #+#    #+#             */
/*   Updated: 2026/10/31 18:52:19 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, char c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str, char *str2)
{
	size_t	strlen;
	size_t	str2len;
	char	*result;

	if (!str || !str2)
		return (NULL);
	strlen = ft_strlen(str);
	str2len = ft_strlen(str2);
	if (strlen > SIZE_MAX - str2len - 1)
		return (NULL);
	result = malloc(strlen + str2len + 1);
	if (!result)
		return (NULL);
	result[strlen + str2len] = '\0';
	while (str2len--)
		result[strlen + str2len] = str2[str2len];
	while (strlen--)
		result[strlen] = str[strlen];
	return (result);
}

char	*extract_line(char *rest)
{
	size_t	len;
	char	*line;
	size_t	i;

	if (!rest)
		return (NULL);
	len = 0;
	if (ft_strchr(rest, '\n'))
		len = ft_strchr(rest, '\n') - rest + 1;
	else
		len = ft_strlen(rest);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
char	*restr(char *nl)
{
	char *result;
	size_t	i;
	size_t	len;

	len = ft_strlen(nl);
	result = malloc(len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		result[i] = nl[i + 1];
		i++;
	}
	result[i] = '\0';
	return (result);

}
int	update_rest(char **rest)
{
	char	*result;
	char	*nl;

	if (!rest || !*rest)
		return (1);
	nl = ft_strchr(*rest, '\n');
	if ((!nl) || (ft_strlen(nl) == 1))
	{
		free(*rest);
		*rest = NULL;
		return (0);
	}
	result = *rest;
	*rest = restr(nl);
	if (!*rest)
	{
		*rest = result;
		return (1);
	}
	free(result);
	return (0);
}
int	add_buffer(char **rest, char *buffer)
{
	char *tmp;

	if (!*rest)
	{
		*rest = malloc(1);
		if (!*rest)
			return (1);
		(*rest)[0] = '\0';
	}
	tmp = ft_strjoin(*rest,buffer);
	if (!tmp)
		return (1);
	free(*rest);
	*rest = tmp;
	return (0);
}
int	read_line(int fd, char **rest)
{
	char	*buffer;
	ssize_t	n;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (1);
	n = read(fd, buffer, BUFFER_SIZE);
	while (n > 0)
	{
		buffer[n] = '\0';
		if (add_buffer(rest, buffer))
		{
			free(buffer);
			return (1);
		}
		if (ft_strchr(*rest, '\n') != NULL)
		{
			free(buffer);
			return (0);
		}
		n = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (n == 0)
		return (0);
	if (n < 0)
	{
		free(*rest);
		*rest = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	int			n;

	if (fd < 0 || (BUFFER_SIZE <= 0))
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	if (rest && ft_strchr(rest, '\n'))
	{
		line = extract_line(rest);
		if ((!line) || (update_rest(&rest) != 0))
		{
			free(rest);
			if (line)
				free(line);
			line = NULL;
			rest = NULL;
			return (NULL);
		}
		if (rest || (line && ft_strlen(line) > 0 && (line[ft_strlen(line) - 1] == '\n')))
			return (line);
	}
	n = read_line(fd, &rest);
	if (n != 0)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = extract_line(rest);
	if ((!line) || (update_rest(&rest) != 0))
	{
		free(rest);
		if (line)
			free(line);
		line = NULL;
		rest = NULL;
		return (NULL);
	}
	return (line);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
	char *line1 = get_next_line(fd);
	char *line2 = get_next_line(fd);
	printf("%s",line);
	printf("%s",line1);
	printf("%s",line2);
	free(line);
	free(line1);
	free(line2);
	close(fd);
}
