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

int		has_break(char *buff, int i)
{
	if (!buff)
		return (0);
	while(*buff)
	{
		if(*buff++ == '\n')
			return (1);
	}
	return (0);
}

void		get_line(char *buff)
{
	static int	i;
	
	if (!i)
		i = 0;

	while(buff[i] != '\n' && buff[i])
	{
		printf("%c", buff[i++]);
	}
	if (buff[i] == '\n')
	{
		printf("%c", buff[i++]);
		// i = 0;
	}
	return ;
}


char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		ret;
	ssize_t		total;
	int			do_once;
	
	if (fd < 0)
		return(NULL);
	total = 0;
	ret = 1;
	do_once = 1;
	printf("\n%ld, %d, XXX%sXXX\n", ret, !has_break(buff), buff);
	if (ret && !has_break(buff))
	{
		while (ret && !has_break(buff))
		{
			ret = read(fd, buff + total, BUFFER_SIZE);
			if ((ret < (ssize_t)(0)) || (!ret && do_once))
			{
				return(NULL);
			}
			total += ret;
			do_once = 0;
		}
		buff[total] = 0;	
	}
	get_line(buff);
	return (buff);
}

//Hello\nHux\n