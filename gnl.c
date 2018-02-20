#include "get_next_line.h"

char	*ft_realloc(char *old, size_t len)
{
	char *new;

	if (old == NULL)
	{
		new = ft_strnew(len);
		return (new);
	}
	new = ft_strnew(ft_strlen(old) + len);
	ft_strcpy(new, old);
	ft_strdel(&old);
	return (new);
}

int		fill_line(char **line, char *buffer)
{
	char	*tmp;
	int		len;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*line = ft_realloc(*line, tmp - buffer);
		ft_strncat(*line, buffer, tmp - buffer);
		ft_memmove(buffer, tmp + 1, ft_strlen(tmp));
		return (LINE);
	}
	if ((len = ft_strlen(buffer)))
	{
		*line = ft_realloc(*line, len);
		ft_strncat(*line, buffer, len);
		*buffer = '\0';
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buffer[BUFF_SIZE];
	int			bytes;

	if (fd < 0 || !line || BUFF_SIZE < 1
		|| (!buffer[fd] && !(buffer[fd] = ft_strnew(BUFF_SIZE))))
		return (ERROR);
	*line = NULL;
	if (fill_line(line, buffer[fd]))
		return (LINE);
	while ((bytes = read(fd, buffer[fd], BUFF_SIZE)) > 0)
	{
		buffer[fd][bytes] = '\0';
		if (fill_line(line, buffer[fd]))
			return (LINE);
	}
	if (*line)
		return (LINE);
	ft_strdel(&buffer[fd]);
	if (bytes < 0)
		return (ERROR);
	return (END);
}
