/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:56:49 by iutahara          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/29 13:03:53 by iuhara           ###   ########.fr       */
=======
/*   Updated: 2024/07/16 13:36:24 by iuhara           ###   ########.fr       */
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*get_line(char *s_buffer)
{
	char	*line;
	char	*line_end;
	char	*line_start;
	int		len;

	if (!s_buffer || *s_buffer == '\0')
		return (NULL);
	line_start = s_buffer;
	if (ft_strchr(s_buffer, '\n'))
	{
		line_end = ft_strchr(s_buffer, '\n');
		line_end++;
	}
	else
		line_end = &s_buffer[ft_strlen(s_buffer)];
	len = line_end - line_start;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_memmove(line, s_buffer, len);
	line[len] = '\0';
	ft_memmove(s_buffer, line_end, ft_strlen(line_end) + 1);
	return (line);
}

char	*get_buffer(int fd, char *s_buffer)
{
	int		read_bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(s_buffer, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		s_buffer = ft_strjoin(s_buffer, buffer);
		if (!s_buffer)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (s_buffer);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s_buffer[fd] = get_buffer(fd, s_buffer[fd]);
	if (!s_buffer[fd])
		return (NULL);
	line = get_line(s_buffer[fd]);
	if (!line)
		return (free(s_buffer[fd]), NULL);
	return (line);
}

<<<<<<< HEAD
int	main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;
	char	*line2;
	char	*line3;

	fd = open("my_file.txt", O_RDONLY);
	fd2 = open("long.txt", O_RDONLY);
	fd3 = open("short.txt", O_RDONLY);
	if (fd == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("open");
		exit(1);
	}
	line = get_next_line(42);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	printf("\n");
	line2 = get_next_line(fd2);
	printf("%s", line2);
	printf("\n");
	line3 = get_next_line(fd3);
	printf("%s", line3);
	printf("\n");
	free(line);
	free(line2);
	free(line3);
	close(fd);
	return (0);
}


__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}
=======
// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("my_file.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		exit(1);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
