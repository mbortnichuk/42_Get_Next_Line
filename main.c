#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


//HERE 1
/*int		main(int argc, char **argv)
{
	int		fd;
	char	*str;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	// while (get_next_line(fd, &str) == 1) // get all lines
	// {
	// 	ft_putendl(str);
	// 	free(str);
	// }

	get_next_line(fd, &str);
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	get_next_line(fd, &str);
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	get_next_line(fd, &str);
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	get_next_line(fd, &str);
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}

	if (argc == 2)
		close(fd);
}*/


//HERE 2
int	main(int ac, char **av)
{

	int	fd0 = 0;
	int	fd;
	//int	fd2;
	//int	fd3;
	char	*line;
	int	nb = 1;
	int	ret;

	(void)ac;
	line = malloc(sizeof(char) * 81);
	line[80] = '\0';
	write(fd0, "aaa\nbbb\n", 8);
	close(fd0);
	ret = get_next_line(fd0, &line);
	//printf("FD :%d line 1 :%s", fd0, line);
	//printf("\n-----------------%d------------------\n", ret);
	//ret = get_next_line(fd0, &line);
	//printf("FD :%d line 2 :%s", fd0, line);
	//printf("\n-----------------%d------------------\n", ret);
	
	fd = open(av[1], O_RDONLY);
	//fd2 = open(av[2], O_RDONLY);
	//fd3 = open(av[3], O_RDONLY);
	while (nb <= 10)
	{
		ret = get_next_line(fd, &line);
		printf("FD :%d line %d:%s", fd, nb++, line);
		printf("\n-----------------%d------------------\n", ret);
		
		/*ret = get_next_line(fd2, &line);
		printf(" FD :%d line %d:%s", fd2, nb++, line);
		printf("\n-----------------%d------------------\n", ret);
		ret = get_next_line(fd3, &line);
		printf(" FD :%d line %d:%s", fd3, nb++, line);
		printf("\n-----------------%d------------------\n", ret);*/
		
	}
	return (0);
}
