#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE    
 # define BUFFER_SIZE 1
#endif

int	has_break(char *buf) 
 { 
 	if (!buf)
 		return (0); 
 	while(*buf && *buf != '\n') 
 		buf++;
	if(*buf == '\n') 
		return (1); 
	return (0); 
 }
 
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

char	*get_next_line(int fd)
{
	char *buf;
	static char *list;
	size_t rbyte;
	int		i;
	
	buf = NULL;
	list = malloc(sizeof(char) * 1);
	*list = '\0';
	rbyte = 1;
	while(rbyte)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		rbyte = read(fd, buf, BUFFER_SIZE);
		printf("<c: %c>\n", *buf);
		buf[rbyte] = 0;
		printf("<buf: %s>\n", buf);
		list = ft_strjoin(list, buf);
		if (has_break(buf))
		{
			// free(buf);
			return (list);	
		}
		// free(buf);
	}
	return (list);
}

// void call_line(void)
// {
// 	int fd;
	
// 	fd = 1;
// 	get_next_line(fd);
// }

// void print_line(void)
// {
// 	char *line;
// 	int fd;
	
// 	fd = 1;
// 	line = get_next_line(fd);
// 	printf("%s", line);
// }

// int main(int argc, char *argv[])
// {
// 	print_line();
// 	print_line();
// 	//call_line();
// 	return (0);
// }
