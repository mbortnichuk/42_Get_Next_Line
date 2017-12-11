/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:02 by mbortnic          #+#    #+#             */
/*   Updated: 2017/12/08 11:37:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_free_strjoin(char *s1, char *s2)
{
	char *temp;

	temp = s1;
	if (!(s1 = ft_strjoin(temp, s2)))
		return (NULL);
	free(temp);
	return (s1);
}

/*static int		ft_is_n(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	ft_add_to_str(char **dst, char **src)
{

}

static int		ft_find_fd(t_gnl **fd_stack, int fd)
{
	t_gnl *temp;

	temp = *fd_stack;

}

int		get_next_line(const int fd, char **line)
{
	char	*buffer;
	int		i;

	i = 0;
	if ((BUFF_SIZE <= 0) || (fd == -1))
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	if ((read(fd, buffer, 0)) == (-1))
		return (-1);

	return (i);
}*/


