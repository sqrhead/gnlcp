#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <stdio.h>
#include <string.h> 

char	*get_next_line(int fd);
size_t	strlen_nl(char *str);
char	*str_inl(const char *buff, const size_t index);
#endif 
