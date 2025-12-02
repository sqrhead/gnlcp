#include "get_next_line.h"

// free, malloc, read
char	*get_next_line(int fd)
{
}
typedef struct s_file 
{
	char		*str;
	size_t		len;
	struct s_file	*next;

}	t_file;

t_file	*fl_new(char *str,size_t len)
{
	t_file *fl = (t_file *)malloc(sizeof(t_file));
	fl->str = str;
	fl->len = len;
	fl->next = NULL;
}
t_file	*fl_lst(t_file *head)
{	
	t_file	*tmp;

	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	fl_add_back(t_file *head,t_file *new)
{
	t_file	*tmp;
	if (!head)
	{
		head = new;
		return ;
	}
	tmp = fl_lst(head);
	tmp->next = new;
}

int main()
{	
	// File Descript 	
	int 	fd;
	// Buffer for write mode
	char	buffer[100];
	// Buffer for read mode
	char	buffr[1024];
	char	**strs;
	size_t	nlines;
	size_t	nbytes;
	
	// WRITE OPERATIONS 
	strcpy(buffer,"ornitorinco");
	fd = open("gnldata.txt",O_WRONLY | O_TRUNC | O_CREAT, 0640);
	//printf("open return : %i\n",fd);
	//printf("buffer	    : %s\n",buffer);
	write(fd,buffer,strlen(buffer));
	close(fd); 
	
	// READ OPERATIONS 
	nbytes = -1;	
	nlines = 0;
	fd = open("gnlrd.txt",O_RDONLY); 
	if (fd == -1)
		return 1; 
	while (nbytes != 0)
	{
		nbytes = read(fd,buffr,1024);
		if (nbytes == -1)
		{
			printf(">> Fail !!\n");
			return (1);
		}
		buffr[nbytes] = '\0';
		printf("buffr \n%s\n",buffr);
		//printf("x\n");
		size_t idx = 0;
		while (buffr[idx])
		{	
			if (buffr[idx] == '\n')
			{
				nlines ++;
			}
			idx ++;
		}	
	}
	close(fd);
	size_t	index = 0;
	printf("buffr : [ %s ]\n",buffr);
	printf("nlines %li\n",nlines);
}
