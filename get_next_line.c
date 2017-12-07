/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:02 by mbortnic          #+#    #+#             */
/*   Updated: 2017/12/06 18:12:45 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}
