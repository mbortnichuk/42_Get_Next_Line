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

// static char *ft_free_strjoin(char *s1, char *s2)
// {
// 	char *temp;

// 	temp = s1;
// 	if (!(s1 = ft_strjoin(temp, s2)))
// 		return (NULL);
// 	free(temp);
// 	return (s1);
// }

// static char		*ft_new_strjoin(char *s1, char const *s2)
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
t_gnl    *ft_multifd(t_gnl **frst, int fd)
{
    t_gnl    *str;

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

char    *ft_trim_free(char *str)
{
    char    *temp;
    int        i;
    int        a;

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

size_t    ft_is_n(char *str, int count, int nlen)
{
    int        i;
    size_t    counter;

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

// char    *ft_strjoin_ch(char const *s1, char c)
// {
//     char    *new;
//     size_t  i;
//     size_t  s1len;

//     if (!s1 || !c)
//         return (NULL);
//     s1len = ft_strlen(s1);
//     new = ft_strnew(s1len + 1);
//     CHECKMEM(new);
//     ft_strdel(new);
//     // if (!new)
//     //     return (NULL);
//     // ft_strdel(&new);
//     i = -1;
//     while (++i < s1len)
//         *(new + i) = *(s1 + i);
//     *(new + i) = c;
//     return (new);
// }

int		ft_strjoin_ch(char **temp, int fd, char **str)
{
	char	*sub;
	char	*buffer;
	ssize_t ret;

	buffer = ft_strnew(BUFF_SIZE);
	ret = read(fd, buffer, BUFF_SIZE);
	if (ret == -1)
		return (ERROR);
	while (ft_is_n(buffer, 1, 0) == 0 && ret > 0)
	{
		sub = *temp;
		*temp = ft_strjoin(sub, buffer);
		ft_strdel(&sub);
		ft_strclr(buffer);
		ret = read(fd, buffer, BUFF_SIZE);
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

// int		get_next_line(const int fd, char **line)
// {
// 	char	*buffer;
// 	int		i;

// 	i = 0;
// 	if ((BUFF_SIZE <= 0) || (fd == -1))
// 		return (-1);
// 	buffer = ft_strnew(BUFF_SIZE);
// 	if ((read(fd, buffer, 0)) == (-1))
// 		return (-1);

// 	return (i);
// }

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	char			*sub;
	t_gnl			*tmp;

	tmp = ft_multifd(&gnl, fd);
	if (ft_strjoin_ch(&tmp->str, fd, &sub) != 0 || line == NULL || BUFF_SIZE < 1)
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
