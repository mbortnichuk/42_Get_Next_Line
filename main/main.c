#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


// //HERE 1
int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;

	char	*str;

	if (argc == 1)
	{
		fd = 0;
		fd2 = 0;
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
	}
	else
		return (2);
	// while (get_next_line(fd, &str) == 1) // get all lines
	// {
	// 	ft_putendl(str);
	// 	free(str);
	// }

	// ft_putnbr(get_next_line(fd, &str));
	// ft_putendl(str);
	// if (str)
	// {
	//  	free(str);
	//  	str = NULL;
	// }
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	// ft_putnbr(get_next_line(fd, &str));
	// ft_putendl(str);
	// if (str)
	// {
	//  	free(str);
	//  	str = NULL;
	// }
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	// ft_putnbr(get_next_line(fd, &str));
	// ft_putendl(str);
	// if (str)
	// {
	//  	free(str);
	//  	str = NULL;
	// }
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	// ft_putnbr(get_next_line(fd, &str));
	// ft_putendl(str);
	// if (str)
	// {
	//  	free(str);
	//  	str = NULL;
	// }
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}
	ft_putnbr(get_next_line(fd2, &str));
	ft_putendl(str);
	if (str)
	{
	 	free(str);
	 	str = NULL;
	}

	if (argc == 3)
		close(fd);
}



// //HERE 2
// int	main(int ac, char **av)
// {

// 	int	fd0 = 0;
// 	int	fd;
// 	int	fd2;
// 	int	fd3;
// 	char	*line;
// 	int	nb = 1;
// 	int	ret;

// 	(void)ac;
// 	line = malloc(sizeof(char) * 81);
// 	line[80] = '\0';
// 	write(fd0, "aaa\nbbb\n", 8);
// 	close(fd0);
// 	ret = get_next_line(fd0, &line);
// 	//printf("FD :%d line 1 :%s", fd0, line);
// 	//printf("\n-----------------%d------------------\n", ret);
// 	//ret = get_next_line(fd0, &line);
// 	//printf("FD :%d line 2 :%s", fd0, line);
// 	//printf("\n-----------------%d------------------\n", ret);
	
// 	fd = open(av[1], O_RDONLY);
// 	fd2 = open(av[2], O_RDONLY);
// 	fd3 = open(av[3], O_RDONLY);
// 	printf("%d\n", fd);
// 	while (nb <= 30)
// 	{
// 		ret = get_next_line(fd, &line);
// 		printf("FD :%d line %d: %s", fd, nb++, line);
// 		printf("\n-----------------%d------------------\n", ret);
		
// 		ret = get_next_line(fd2, &line);
// 		printf(" FD :%d line %d: %s", fd2, nb++, line);
// 		printf("\n-----------------%d------------------\n", ret);

// 		ret = get_next_line(fd3, &line);
// 		printf(" FD :%d line %d:%s", fd3, nb++, line);
// 		printf("\n-----------------%d------------------\n", ret);
		
// 	}
// 	return (0);
// }




/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	string = ft_memalloc(1 + ft_strlen(s1) + ft_strlen(s2));
	if (!string)
		return (NULL);
	return (ft_strcat(ft_strcpy(string, s1), s2));
}

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*arr;

	if (size > 0)
	{
		i = 0;
		arr = (char *)malloc(sizeof(char) * size);
		if (arr != NULL)
		{
			while (size > 0)
			{
				arr[i] = 0;
				size--;
				i++;
			}
			return (arr);
		}
		return (NULL);
	}
	return (NULL);
}
char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len + i] = s2[i];
		i++;
	}
	s1[len + i] = '\0';
	return (s1);
}*/

// size_t	ft_strlen(const char *s)
// {
// 	size_t i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char		*ft_free_strjoin(char *s1, char *s2)
// {
// 	char *fresh;
// 	char *ptr;
// 	char *tmp;

// 	tmp = NULL;
// 	fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (fresh)
// 	{
// 		tmp = fresh;
// 		if (s1)
// 		{
// 			ptr = s1;
// 			while (*s1)
// 				*(fresh++) = *(s1++);
// 			free(ptr);
// 			s1 = NULL;
// 		}
// 		if (s2)
// 			while (*s2)
// 				*(fresh++) = *(s2++);
// 		*fresh = '\0';
// 	}
// 	return (tmp);
// }


// char *ft_free_strjoin(char *s1, char *s2)
// {
// 	char *tmp;

// 	tmp = s1;
// 	if (!(s1 = ft_strjoin(tmp, s2)))
// 		return (NULL);
// 	free(tmp);
// 	return (s1);
// }

//HERE
// #include "get_next_line.h"
// #include <fcntl.h>

// int		main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*str;

// 	if (argc == 1)
// 		fd = 0;
// 	else if (argc == 2)
// 		fd = open(argv[1], O_RDONLY);
// 	else
// 		return (2);
// 	while (get_next_line(fd, &str) == 1)
// 	{
// 		ft_putendl(str);
// 		free(str);
// 	}
// 	if (argc == 2)
// 		close(fd);
// }

// int main()
// {
	// int fd;
	// char *str;

	// str = NULL;
	// fd = open("file.txt", O_RDONLY);

	// if (fd == -1)
	// 	return (-1);

	// get_next_ine(fd, &str);
// 	// printf("text: %s\n", str);

// 	char *s1 = "hello ";
// 	char *s2 = "world";
// 	printf("free_join: %s\n", ft_free_strjoin(s1, s2));

// 	return (0);
// }
