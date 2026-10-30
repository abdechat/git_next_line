/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 14:37:44 by achancha          #+#    #+#             */
/*   Updated: 2026/10/30 17:42:45 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
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
	if (strlen > SIZE_MAX - str2len -1)
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

char *extract_line(char *rest)
{
	size_t len;
	char *line;
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

int update_rest(char **rest)
{
	char *result;
	char *nl;
	size_t len;
	size_t i;

	if (!rest || !*rest)
		return (1);
	nl = ft_strchr(*rest,'\n');
	if ((!nl) || (ft_strlen(nl) == 1))
	{
		free(*rest);
		*rest = NULL;
		return (0);
	}
	result = *rest;
	len = ft_strlen(nl) - 1;
	(*rest) = malloc(len + 1);
	if (!(*rest))
	{
		*rest = result;
		return 1;
	}
	(*rest)[len] = '\0';
	i = 0;
	while (i < len)
	{
		(*rest)[i] = nl[i +1];
		i++;
	}
		free(result);
	return (0);
}

int main()
{
	char *rest;

	rest = malloc(3);
	rest[0] = 'A';
	rest[1] = '\n';
	rest[2] = 'B';
	printf("%s",extract_line(rest));
	update_rest(&rest);
	printf("%s",rest);
}
