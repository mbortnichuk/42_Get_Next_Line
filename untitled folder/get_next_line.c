/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:02 by mbortnic          #+#    #+#             */
/*   Updated: 2017/12/22 10:43:01 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_multifd(t_gnl **frst, int fd)
{
	t_gnl	*str;

	str = *frst;
	while (str != NULL)
	{
		if (str->fd == fd)
			return (str);
		str = str->next;
	}
	str = (t_gnl *)malloc(sizeof(t_gnl));
	if (!(str->str = ft_strnew(0)))
		return (NULL);
	str->fd = fd;
	str->next = *frst;
	*frst = str;
	return (str);
}

char	*ft_trim_free(char *str)
{
	char	*temp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	temp = ft_strnew(ft_strlen(str));
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
		temp[a++] = str[i++];
	ft_strdel(&str);
	temp[a] = '\0';
	return (temp);
}

int		ft_is_n(char *str, int count, int nlen)
{
	int		i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (str)
	{
		while (str[i] && count == 1)
			if (str[i++] == '\n')
				counter++;
		while (str[i] != '\n' && str[i++] != '\0' && nlen == 1)
			counter++;
	}
	return (counter);
}

int		ft_strjoin_ch(char **temp, int fd, char **str)
{
	char	*sub;
	char	*buffer;
	ssize_t bytes;

	buffer = ft_strnew(BUFF_SIZE);
	bytes = read(fd, buffer, BUFF_SIZE);
	if (bytes == -1)
		return (ERROR);
	while (ft_is_n(buffer, 1, 0) == 0 && bytes > 0)
	{
		sub = *temp;
		*temp = ft_strjoin(sub, buffer);
		ft_strdel(&sub);
		ft_strclr(buffer);
		bytes = read(fd, buffer, BUFF_SIZE);
	}
	sub = *temp;
	*temp = ft_strjoin(sub, buffer);
	ft_strdel(&sub);
	ft_strdel(&buffer);
	sub = ft_strsub(*temp, 0, ft_is_n(*temp, 0, 1));
	if (sub == NULL)
		sub = ft_strnew(0);
	*str = sub;
	return (END);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	char			*sub;
	t_gnl			*tmp;

	tmp = ft_multifd(&gnl, fd);
	if (ft_strjoin_ch(&tmp->str, fd, &sub) != 0 || \
		line == NULL || BUFF_SIZE < 1)
		return (ERROR);
	if (*sub == '\0' && ft_is_n(tmp->str, 1, 0) == 0)
	{
		*line = sub;
		return (END);
	}
	if (ft_is_n(tmp->str, 1, 0) > 0)
	{
		*line = sub;
		tmp->str = ft_trim_free(tmp->str);
		return (LINE);
	}
	*line = sub;
	ft_strclr(tmp->str);
	return (LINE);
}
