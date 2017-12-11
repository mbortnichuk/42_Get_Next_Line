/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:22 by mbortnic          #+#    #+#             */
/*   Updated: 2017/12/08 11:28:25 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

#include "libft/libft.h"

# define ERROR -1
# define END 0
# define LINE 1

# define BUFF_SIZE 50

typedef struct s_gnl
{
	char *str;
	int fd;
	struct s_gnl *next;
}	t_gnl;

int	get_next_line(const int fd, char **line);

char	*ft_free_strjoin(char *s1, char *s2);

#endif
