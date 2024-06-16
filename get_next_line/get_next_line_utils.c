/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerbs <yerbs@student.42mulhouse.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:21:34 by yerbs             #+#    #+#             */
/*   Updated: 2024/06/13 18:15:03 by yerbs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*gnl_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &str[i]);
	return (0);
}

char	*gnl_strjoin(char *line, char *buff)
{
	char	*full_line;
	int		len_line;
	int		len_buff;

	if (!line)
		line = (char *)gnl_calloc(1, sizeof(char));
	if (!line || !buff)
		return (NULL);
	len_line = gnl_strlen(line);
	len_buff = gnl_strlen(buff);
	full_line = (char *)gnl_calloc(len_line + len_buff + 1, sizeof(char));
	if (!full_line)
	{
		free(line);
		return (NULL);
	}
	gnl_memmove(full_line, line, len_line);
	gnl_memmove(full_line + len_line, buff, len_buff + 1);
	free(line);
	return (full_line);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest_ptr > src_ptr)
		while (n--)
			dest_ptr[n] = src_ptr[n];
	else
		while (n--)
			*dest_ptr++ = *src_ptr++;
	return (dest);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = gnl_strlen(s);
	if (start >= len_s)
		return (0);
	if (len_s - start < len)
		len = len_s - start;
	sub = gnl_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	gnl_memmove(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	len;
	size_t	i;

	len = nmemb * size;
	if (len / size != nmemb)
		return (NULL);
	tab = malloc(len);
	if (!tab)
		return (0);
	i = 0;
	while (i < len)
		((char *) tab)[i++] = 0;
	return (tab);
}
