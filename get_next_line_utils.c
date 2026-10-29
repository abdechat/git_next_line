/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:23:43 by achancha          #+#    #+#             */
/*   Updated: 2026/10/29 20:41:35 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

char	*ft_strchr(char *str, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (str[i] == '\n')
			return (&str[i + 1]);
		i++;
	}
	return (0);
}
size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *str, char *st)
{
	char	*res;
	size_t	strlen;
	size_t	stlen;

	strlen = ft_strlen(str);
	stlen = ft_strlen(st);
	if ((strlen > SIZE_MAX - stlen) || (strlen + stlen == SIZE_MAX))
		return (NULL);
	res = malloc(strlen + stlen + 1);
	if (!res)
		return (NULL);
	res[strlen + stlen] = '\0';
	while (stlen--)
		res[strlen + stlen] = st[stlen];
	while (strlen--)
		res[strlen] = str[strlen];
	free(str);
	return (res);
}

void ft_rest(char **rest, char *s)
{
	size_t len;
	char *rr;

	rr = *rest;
	len = ft_strlen(s);
	*rest = malloc(len + 1);
	if (!(*rest))
		return (NULL);
	free(rr);
	(*rest)[len] = '\0';
	while (len--)
		(*rest)[len] = s[len];
}

char *ft_read(int fd, char *res, char **rest)
{
	ssize_t n;
	char *s;
	char *tmp;
	char buffer[BUFFER_SIZE + 1];

	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if ((s = ft_strchr(buffer, n)) != 0)
		{
			ft_rest(rest ,s);
			*s = '\0';
			tmp = res;
			res = ft_join(res, buffer);
			if (!res)
				return (tmp);
			return (res);
		}
		tmp = res;
		res = ft_join(res, buffer);
		if (!res)
			return (tmp);
	}
	if (n == 0)
		return (res);
	if (n < 0)
		return (NULL);
}

char *ft_mazal(char **rest, char res)
{
	char *s;

	s = ft_strchr(rest, ft_strlen(rest));
	ft_rest(rest, s);
}

char *get_next_line(int fd)
{
	static char *rest;
	char *res;
	size_t rest_len;

	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (rest != NULL)
	{
		rest_len = ft_strlen(rest);
		if (ft_strchr(rest, rest_len) != 0)
			return (ft_mazal(&rest, res));

		res = ft_join(rest, res);
	}
	res = ft_read(fd, res, &rest);
	return (res);
}

int	main(void)
{
	printf("%s\n", (char *)ft_strchr("abde\nchanchaf", 10));
	printf("%s\n", ft_join("abderrahim", "chanchaf"));
}
