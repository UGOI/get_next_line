/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:47:48 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/03 17:43:07 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*res_cast;
	size_t	total_len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	res_cast = res;
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
		*res_cast++ = s1[i++];
	free(s1);
	while (*s2)
		*res_cast++ = *s2++;
	*res_cast = '\0';
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_char;
	const char	*src_char;

	if (!dest && !src && n)
		return (NULL);
	dest_char = dest;
	src_char = src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

char	*ft_initialize(size_t size)
{
	char	*res;

	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	*res = 0;
	return (res);
}

int	strjoin_parser(char **list, char **buf)
{
	char	*parsed_buf;
	int		i;

	if (!*buf || **buf == 0)
		return (0);
	if (*list == NULL)
		*list = ft_initialize(1);
	i = 0;
	while ((*(*buf + i)) != 0 && (*(*buf + i)) != '\n')
		i++;
	if (*(*buf + i) == 0)
	{
		*list = ft_strjoin(*list, *buf);
		return (0);
	}
	i++;
	parsed_buf = malloc(sizeof(char) * (i + 1));
	*(parsed_buf + i) = 0;
	ft_memcpy(parsed_buf, *buf, (i));
	*list = ft_strjoin(*list, parsed_buf);
	free(parsed_buf);
	ft_memcpy(*buf, *buf + i, ft_strlen(*buf + i) + 1);
	return (1);
}
