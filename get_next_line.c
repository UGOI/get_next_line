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
#ifndef BUFFER_SIZE    
 # define BUFFER_SIZE 1
#endif

char*get_next_line(int fd)
{
	char	*buf;
	size_t	ret;

	printf("%d\n", BUFFER_SIZE);

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	
	ret = read(fd, buf, BUFFER_SIZE);
	if (!ret)
		return(NULL);
	buf[ret] = 0;
	return (buf);
}
