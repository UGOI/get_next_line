#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 1
#endif

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
	{
		*res_cast++ = s1[i++];
	}
	free(s1);
	while (*s2)
	{
		*res_cast++ = *s2++;
	}
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

int	strjoin_parser(char **list, char **buf)
{
	char			*parsed_buf;
	int				i;

	if (**buf == 0)
		return (1);
	if (*list == NULL)
	{
		*list = malloc(sizeof(char) * 1);
		**list = '\0';
	}
	i = 0;
	while ((*(*buf + i)) != 0 && (*(*buf + i)) != '\n')
	{
		i++;
	}
	if (*(*buf + i) == 0)
	{
		*list = ft_strjoin(*list, *buf);
		free(*buf);
		i = 0;
		return (1);
	}
	else if (*(*buf + i) == '\n')
	{
		i++;
		parsed_buf = malloc(sizeof(char) * (i + 1));
		*(parsed_buf + i) = 0;
		parsed_buf = ft_memcpy(parsed_buf, *buf, (i));
		*list = ft_strjoin(*list, parsed_buf);
		free(parsed_buf);

		// printf("strlen:[%zu]\n", ft_strlen(*buf + i));
		// printf("buf1:[%s], buf+i:[%s]\n", *buf, *buf + i);
		memmove(*buf, *buf + i, ft_strlen(*buf + i) + 1);
		// printf("buf2:[%s]\n", *buf);
		return (0);
	}
	else
		return (-1);
}

char	*get_next_line(int fd)
{
	static char		*buf;
	static char 	*list;
	ssize_t			rbyte;
	static int		joined_end = 1;

	// printf("GET_NEXT_LINE:\n");
	// if (BUFFER_SIZE <= 0)
	// 	return (NULL);
	if (joined_end)
		buf = NULL;
	list = NULL;
	rbyte = 1;
	while(rbyte)
	{
		if (joined_end)
		{
			// printf("buf: %s\n", buf);
			buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!buf)
				return (NULL);
			rbyte = read(fd, buf, BUFFER_SIZE);
			if (rbyte == 0)
				return (list);
			if (rbyte < (ssize_t)(0))
			{
				free(buf);
				return(NULL);
			}
			buf[rbyte] = 0;
		}
		joined_end = strjoin_parser(&list, &buf);
		// printf("joined_end: %d\n", joined_end);
		if (joined_end == -1)
			printf("Error: joined_end is -1.\n");
		if (!joined_end)
			return (list);
	}
	if (ft_strlen(list) == 0)
		return (NULL);
	return (list);
}
