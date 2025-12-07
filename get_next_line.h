#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <stdio.h>
#include <string.h> 

char	*get_next_line(int fd);
char	*get_line(char *buffer);
char 	*buffer_resize(char *buffer, char *str);
char	*join_buffers(char *buffer, char *read_buffer);
int	    has_newline(char *buffer);
//strlen
//memcpy





#endif 
