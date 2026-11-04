/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:40:54 by achancha          #+#    #+#             */
/*   Updated: 2026/11/04 17:07:40 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2211
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_all
{
	char	buffer[BUFFER_SIZE];
	ssize_t	re;
	ssize_t	ind;
}	t_all;

char	*get_next_line(int fd);
char	*add_buffer(char *str, char c);
char	*ft_free(char *str);

#endif
