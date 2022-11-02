/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdukic <sdukic@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:41:43 by sdukic            #+#    #+#             */
/*   Updated: 2022/11/02 23:53:49 by sdukic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../get_next_line.h"
#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void	t_ft_strlen(void)
{
	printf("STRLEN:\n");
	char	*s = "H\n";
	size_t 	i;

	i = ft_strlen(s);
	printf("%zu\n", i);
}

void	t_ft_strjoin(void)
{
	printf("STRJOIN:\n");
	char	*s1;
	char	*s2;

	s1 = malloc(sizeof(char) * 6);
	s2 = malloc(sizeof(char) * 7);
	strcpy(s1, "IAmS1-");
	strcpy(s2, "IAmS2\n");
	s1 = ft_strjoin(s1, s2);
	printf("%s", s1);
}

void	t_ft_memcpy(void)
{
	printf("MEMCPY:\n");
	char	*s1;
	char	*s2;
	size_t	n;

	s1 = malloc(sizeof(char) * 8);
	s2 = malloc(sizeof(char) * 8);
	strcpy(s1, "CopyMe\n");
	n = 8;
	ft_memcpy(s2, s1, n);
	printf("%s", s2);
}

void	t_strjoin_parser(void)
{
	printf("STRJOIN_PARSER:\n");
	char	*list;
	char	*list2;
	char	*s2;
	char	*s3;
	int		joined_end;

	list = malloc(sizeof(char) * 8);
	list2 = malloc(sizeof(char) * 9);
	s2 = malloc(sizeof(char) * 10);
	s3 = malloc(sizeof(char) * 9);
	strcpy(list, "JoinMe-");
	strcpy(list2, "JoinMe2-");
	strcpy(s2, "App\nendme");
	strcpy(s3, "TILLNOW\n");
	joined_end = strjoin_parser(&list, &s2);
	joined_end = strjoin_parser(&list2, &s3);
	printf("list: %s\n", list);
	printf("list2: %s\n", list2);
}

void	t_get_next_line(int fd)
{
	printf("GET_NEXT_LINE:\n");
	int			i;
	char		*buf;

	i = 1;
	while (i--)
	{
		buf = get_next_line(fd);
		if (buf)
		{
			printf("%s", buf);
		}
		free(buf);
	}
}

int main(void)
{
	int	fd;

	// fd = open("files/empty", O_RDWR);
	fd = open("text.txt", O_RDONLY | O_CREAT);
	// fd = open("files/41_no_nl", O_RDWR);
	// fd = 1000;
	// printf("%d\n", fd),
	t_get_next_line(fd);

	// t_ft_strlen();
	// t_ft_strjoin();
	// t_ft_memcpy();
	// t_strjoin_parser();
}
