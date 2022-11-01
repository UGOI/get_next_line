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

int		has_break(char *buff, int length)
{
	int	i;

	// printf("%c", *buff);
	// printf("\n%d\n", length);
	// printf("KAMy\n");
	if (!buff)
		return (0);
	i = 0;
	if(*buff == '\n')
			return (1);
	while(*buff && i < length)
	{
		if(*buff++ == '\n')
			return (1);
		i++;
	}
	return (0);
}

void		get_line(char **buff)
{
	// printf("%c\n", **buff);
	while(**buff != '\n' && **buff)
	{
		printf("Hello\n");
		printf("%c", **buff);
		(*buff)++;
	}
	if (**buff == '\n')
	{
		printf("%c", **buff);
		(*buff)++;
	}
	return ;
}


char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	ssize_t		ret;
	ssize_t		total;
	int			do_once;
	
	if (fd < 0)
		return(NULL);
	total = 0;
	ret = 0;
	do_once = 1;
	buff = NULL;
	line = (char *)malloc(sizeof(char) * (100));
	if (!line)
		return(NULL);
	if ((ret && !has_break(buff + total, ret)) || do_once)
	{
		while ((ret && !has_break(buff + total, ret)) || do_once)
		{
			total += ret;	
			buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!buff)
				return(NULL);
			// printf("%ld, %d\n", total, BUFFER_SIZE + 1);
			ret = read(fd, buff + total, BUFFER_SIZE);
			// printf("%d", *(buff + total));
			if ((ret < (ssize_t)(0)) || (!ret && do_once))
			{
				free(buff);
				return(NULL);
			}

			do_once = 0;
			// printf("\nret: %ld, has_break: %d, buff: %s\n", ret, !has_break(buff), buff);
			printf("%c", *(buff + total));
			*(line++) = (buff + total);
		}
		// buff[total + 1] = 0;
	}
	// printf("-%c-", *(buff));
	// get_line(&buff);
	return (buff);
}

//Hello\nHux\n