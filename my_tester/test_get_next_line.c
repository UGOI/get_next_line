/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:41:43 by sdukic            #+#    #+#             */
/*   Updated: 2022/10/25 15:43:55 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../get_next_line.h"
#include"stdio.h"
#include <sys/stat.h>
#include <fcntl.h>

void	print_get_next_line(int fd)
{
	char	*buf;

	while (buf)
	{
		buf = get_next_line(fd);
		if (buf)
			printf("%s", buf);
	}
}

int main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY | O_CREAT);
	print_get_next_line(fd);
	print_get_next_line(1);
}
 