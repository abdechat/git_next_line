/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:23:43 by achancha          #+#    #+#             */
/*   Updated: 2026/10/29 14:55:08 by achancha         ###   ########.fr       */
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

char	*ft_join(char *str, char *st)
{
	char	*res;
	size_t	strlen;
	size_t	stlen;

	strlen = 0;
	stlen = 0;
	while (str[strlen])
		strlen++;
	while (st[stlen])
		stlen++;
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
	size_t i;
	char *rr;

	rr = *rest;
	i = 0;
	while (s[i])
		i++;
	*rest = malloc(i + 1);
	if (!(*rest))
		return (NULL);
	free(rr);
	(*rest)[i] = '\0';
	while (i--)
		(*rest)[i] = s[i];
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

char *get_next_line(int fd)
{
	static char *rest;
	char *res;
	char *hh;
	size_t i;

	i = 0;
	res = malloc(1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (rest != NULL)
	{
		while (rest[i])
			i++;
		if (ft_strchr(rest, ) != 0)
		{
			hh = rest;
			ft_rest(hh, rest);
			*hh = '\0';
			tmp = res;
			res = ft_join(res, rest);

			if (!res)
				return (NULL);
			return (res);
		}
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
