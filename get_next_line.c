/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:48:05 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/03 17:46:04 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_output(char **buf, char *list, int rbyte)
{
	if (rbyte <= 0)
	{
		free(*buf);
		if (rbyte == -1)
		{
			free(list);
			return (NULL);
		}
		return (list);
	}
	return (list);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*list;
	ssize_t		rbyte;
	static int	joined_end;

	list = NULL;
	rbyte = 1;
	if (!joined_end)
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		if (!joined_end)
		{
			rbyte = read(fd, buf, BUFFER_SIZE);
			if (rbyte <= 0)
				return (ft_output(&buf, list, rbyte));
			buf[rbyte] = 0;
		}
		joined_end = strjoin_parser(&list, &buf);
		if (joined_end)
			return (ft_output(&buf, list, rbyte));
	}
}
