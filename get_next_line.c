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

#include<unistd.h>
#include<stdio.h>

char	*get_next_line(int fd)
{
	char	buf[10];
	int		ret;

	ret = read(0, buf, 10);
	printf("%s\n", buf);
	return (NULL);
}
