#include "get_next_line.h"

// free, malloc, read
char	*get_next_line(int fd)
{
}

int main()
{	
	int 	fd;
	char	buffer[100];
	char	buffer_read[100];
	
	strcpy(buffer,"ornitorinco");
	fd = open("gnldata.txt",O_WRONLY | O_TRUNC | O_CREAT, 0640);
	printf("open return : %i\n",fd);
	printf("buffer	    : %s\n",buffer);
	write(fd,buffer,strlen(buffer));
	close(fd); 
	fd = open("gnlrd.txt",O_RDONLY); 
	if (fd == -1)
		return 1; 
}
