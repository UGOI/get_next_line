/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:41:43 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/01 21:29:50 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../get_next_line.h"
#include"stdio.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void	print_get_next_line(int fd)
{
	// char		*buf;
	int			i;
	char		*buf;

	i = 4;
	while (i--)
	{
		buf = get_next_line(fd);
		if (buf)
		{
			printf("%s", buf);
		}
		free(buf);
	}
	printf("TEST END\n");

}

int main(void)
{
	int	fd;

	// fd = open("files/empty", O_RDWR);
	fd = open("text.txt", O_RDONLY | O_CREAT);
	// fd = open("files/41_no_nl", O_RDWR);
	// fd = 1000;
	// printf("%d\n", fd),
	print_get_next_line(fd);
}
 