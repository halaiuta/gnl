/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:35:31 by iutahara          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/29 13:04:21 by iuhara           ###   ########.fr       */
=======
/*   Updated: 2024/07/16 13:35:37 by iuhara           ###   ########.fr       */
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
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

// int	main(void)
// {
// 	int		fd;
<<<<<<< HEAD
// 	int		i;
// 	char	*line;
// 	// char	*line2;
// 	// char	*line3;
// 	// char	*line4;
// 	// char	*line5;
// 	// char	*line6;
// 	// char	*line7;

// 	i = 0;
=======
// 	char	*line;

>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
// 	fd = open("my_file.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		exit(1);
// 	}
<<<<<<< HEAD
// 	// fd = 42;
// 	// while (i < 10)
// 	// {
// 		line = get_next_line(42);
// 		printf("%d %s", i, line);
// 		free(line); 
// 		// line2 = get_next_line(fd);
// 		// printf("%d %s", i, line2);
// 		// free(line2); 
// 		// line3 = get_next_line(fd);
// 		// printf("%d %s", i, line3);
// 		// free(line3); 
// 		// line4 = get_next_line(fd);
// 		// printf("%d %s", i, line4);
// 		// free(line4); 
// 		// line5 = get_next_line(fd);
// 		// printf("%d %s", i, line5);
// 		// 	free(line5);
// 		// line6 = get_next_line(fd);
// 		// printf("%d %s", i, line6);
// 		// 	free(line6);
// 		// line7 = get_next_line(fd);
// 		// printf("%d %s", i, line7);
// 		// 	free(line7);
// 	// 	i++;
// 	// }
// 	close(fd);
// 	return (0);
// }
=======
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }

/*
複数回のread
*/
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
