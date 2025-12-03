#include "get_next_line.h"

#define BUFFSIZE 1024
size_t	strlen_nl(char *str)
{
	size_t	len;
	size_t	index;

	index = 0;
	len = 0;
	while (str[len])
	{	
		if (str[len] == '\n')
		{
			return (len);
		}
		len ++;
	}
	return (len);
}
// free, malloc, read
char	*get_next_line(int fd)
{
	size_t		nbytes;
	static size_t	index;
	size_t		mark;
	size_t		len;
	static char	*str;
	char		*line;

	nbytes = 0;
	index = 0;
	mark = 0;
	if (str == NULL )
		str = (char *)calloc(BUFFSIZE,sizeof(char));
	if (str[0] == '\0')
	{	
		printf("str empty \n");
		nbytes = read(fd,str,BUFFSIZE);
	}
	if (nbytes < 0)
		return (NULL);
	if (index < BUFFSIZE)
	{	
		len = strlen_nl(str);
		line = (char *)malloc(sizeof(char) * (len + 1));
		memcpy(line,str,len);
		//free(str);
		return (line);
	}
	printf("FAIL_GET_NEXT_LINE\n");
	return (NULL);
}

int main()
{	
	// File Descript 	
	int 	fd;
	// Buffer for write mode
	char	*buffr;
	char	*buffx;
	char	*buffy;

	fd = open("gnlrd.txt",O_RDONLY);
	buffr = get_next_line(fd);
	printf("output  [ %s ]\n",buffr);
	buffx = get_next_line(fd);
	printf("outputx [ %s ]\n",buffx);
	buffy = get_next_line(fd);
	printf("outputy [ %s ]\n",buffy);

	free(buffr);	
	free(buffx);
	free(buffy);
	close(fd);
	
	
}
