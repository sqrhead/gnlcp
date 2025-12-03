#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#ifndef DEBUG 
# define DEBUG 0
#endif
// free, malloc, read
// static char* to keep the state 
// static size_t as index for the next string to get
char	*get_next_line(int fd)
{
		static size_t		internal_index = 0; // check static initialization
		static char		*buffer = NULL; 
		size_t			bytes;
		char			*str;
		size_t			len;
		size_t			i; 
	
		len = 0;
		i = 0;
		str = NULL;
		if (!buffer)
		{
			printf("calloc . . . \n");
			buffer = (char *)calloc(BUFFER_SIZE,sizeof(char));
			if (!buffer)
				return (NULL);
			printf("read . . .\n");
			bytes = read(fd,buffer,BUFFER_SIZE);
			if (bytes == 0)
				return (NULL);
		}
		printf("INFO : pre_internal index %li\n",internal_index);
		if (DEBUG == 1 && internal_index < 1)
		{
			printf("buffer : \n%s\n",buffer);
		}
		while (buffer[i + internal_index])
		{	
			if (!buffer[i + internal_index + 1])
			{
				printf("INFO : EOF REACHED\n");
				return (NULL);
			}
			if (buffer[i + internal_index] == '\n' || !buffer[i + internal_index])
				break;
			len ++;
			i ++;	
		}
		// malloc and cpy
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		memcpy(str,buffer + internal_index,len);
		str[len] = '\0';
		internal_index = internal_index + len + 1;
		return (str);
		
}
/*
int main()
{	

	size_t	fd;
	char	*ln;
	char	*ln2;
	size_t	i;
	size_t	iter;

	i = 0;
	iter = 11;
	fd = open("gnlrd.txt",O_RDONLY);
	while (i < iter)
	{
		ln = get_next_line(fd);
		if (ln == NULL)
		{
			printf("INFO : iter %li\n",i);
			printf("INFO : ln null\n");
		}
		else
		{
			printf("INFO : iter %li\n",i);
			printf("INFO : ln %s\n",ln);
		}
		i ++;
	}

	free(ln);
	close(fd);
}
*/
