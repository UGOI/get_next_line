/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:53:15 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/25 15:46:25 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE    
 # define BUFFER_SIZE 10
#endif

int		has_break(char *buf)
{
	if (!buf)
		return (0);
	while(*buf)
	{
		if(*buf++ == '\n')
			return (1);
	}
	return (0);
}

char	*get_line_length(int fd)
{
	char		*buf;
	ssize_t		ret;
	ssize_t		total;
	int			do_once;
	
	if (fd < 0)
		return(NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	total = 0;
	ret = 1;
	do_once = 1;
	while (ret)
	{
		ret = read(fd, buf + total, BUFFER_SIZE);
		if ((ret < (ssize_t)(0)) || (!ret && do_once))
		{
			free(buf);
			return(NULL);
		}
		total += ret;
		do_once = 0;
	}
	buf[total] = 0;
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	// char		*line;
	ssize_t		ret;
	ssize_t		total;
	int			do_once;
	
	if (fd < 0)
		return(NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	total = 0;
	ret = 1;
	do_once = 1;
	while (ret && !has_break(buf))
	{
		// printf("%s\n", buf);
		ret = read(fd, buf + total, BUFFER_SIZE);
		if ((ret < (ssize_t)(0)) || (!ret && do_once))
		{
			free(buf);
			return(NULL);
		}
		total += ret;
		do_once = 0;
	}
	buf[total] = 0;
	return (buf);
}

//Hello