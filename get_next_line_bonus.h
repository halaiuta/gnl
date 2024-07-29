/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuhara <iuhara@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:55:03 by iutahara          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/20 18:09:05 by iuhara           ###   ########.fr       */
=======
/*   Updated: 2024/07/12 20:36:04 by iuhara           ###   ########.fr       */
>>>>>>> 234c7ad569d2f0202816b3c360466af2e397c323
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
char	*get_buffer(int fd, char *s_buffer);
char	*get_line(char *buffer);
char	*ft_create_s1(char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif
