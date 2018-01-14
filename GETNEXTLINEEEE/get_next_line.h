/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:51:22 by mbortnic          #+#    #+#             */
/*   Updated: 2018/01/14 19:18:12 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

#include "libft/libft.h"

# define ERROR -1
# define END 0
# define LINE 1

# define BUFF_SIZE 2
# define FDS 4864

#define CHECK(x) if (!x) return (0);

int				get_next_line(const int fd, char **line);

#endif
