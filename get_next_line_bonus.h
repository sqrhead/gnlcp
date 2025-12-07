/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:40:33 by sqrhead           #+#    #+#             */
/*   Updated: 2025/12/07 23:04:47 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

char	*get_next_line(int fd);
char	*get_line(char *buffer);
char	*buffer_resize(char *buffer, char *str);
char	*join_buffers(char *buffer, char *read_buffer);
int		has_newline(char *buffer);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *to, const void *from, size_t nbytes);
char	*is_eof(char **buffer);

#endif