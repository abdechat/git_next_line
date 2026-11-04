/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achancha <achancha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:24:19 by achancha          #+#    #+#             */
/*   Updated: 2026/11/02 14:20:21 by achancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1122
# endif

# include <unistd.h>
# include <stdlib.h>

char	*add_buffer(char *str, char c);
char	*ft_free(char *line);
char	*get_next_line(int fd);

#endif
