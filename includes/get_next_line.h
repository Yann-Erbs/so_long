/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:20:04 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/13 18:18:44 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*gnl_strchr(const char *str, int c);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *line, char *buff);

size_t	gnl_strlen(const char *str);

void	ft_update(char **line, char *buffer);
void	ft_read(int fd, char **line, char *buffer, int *br);
void	*gnl_memmove(void *dest, const void *src, size_t n);
void	*gnl_calloc(size_t nmemb, size_t size);

int		ft_check(int br, char **line);

#endif