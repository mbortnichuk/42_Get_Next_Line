#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

char* my_realloc(char* ptr, size_t size)
{
    char* temp;
    int i;

    temp = ptr;
    ptr = malloc(size);
    i = 0;
    while(temp[i])
    {
        ptr[i] = temp[i];
        i++;
    }
    free(temp);
    return (ptr);
}

char get_char(const int fd)
{
    static char buff[BUFFER_SIZE];
    static char* ptr_buff;
    static int len = 0;
    char c;

    if(len == 0)
    {
        len = read(fd, buff, BUFFER_SIZE);
        ptr_buff = (char*)&buff;
        if(len == 0)
            return (0);
    }
    c = *ptr_buff;
    ptr_buff++;
    len--;
    return c;
}

char *get_next_line(const int fd)
{
    char c;
    char* str;
    int len;

    len = 0;
    str = malloc(BUFFER_SIZE + 1);
    if (str == NULL)
        return (0);
    c = get_char(fd);
    while(c != '\n' && c != '\0')
    {
        str[len] = c;
        c = get_char(fd);
        len++;
        if(len % (BUFFER_SIZE+1) == 0)
            str = my_realloc(str, len + BUFFER_SIZE + 1);
    }
    str[len] = 0;
    if(c == 0 && str[0] == 0)
        return (0);
    return (str);
}




//HERE

# define MALLCHECK(x) if (!x) return (-1);

static t_list           *get_correct_file(t_list **file, int fd)
{
    t_list              *tmp;

    tmp = *file;
    while (tmp)
    {
        if ((int)tmp->content_size == fd)
            return (tmp);
        tmp = tmp->next;
    }
    tmp = ft_lstnew("\0", fd);
    ft_lstadd(file, tmp);
    tmp = *file;
    return (tmp);
}

int                     get_next_line(const int fd, char **line)
{
    char                buf[BUFF_SIZE + 1];
    static t_list       *file;
    int                 i;
    int                 ret;
    t_list              *curr;

    if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
        return (-1);
    curr = get_correct_file(&file, fd);
    MALLCHECK((*line = ft_strnew(1)));
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        buf[ret] = '\0';
        MALLCHECK((curr->content = ft_strjoin(curr->content, buf)));
        if (ft_strchr(buf, '\n'))
            break ;
    }
    if (ret < BUFF_SIZE && !ft_strlen(curr->content))
        return (0);
    i = ft_copyuntil(line, curr->content, '\n');
    (i < (int)ft_strlen(curr->content))
        ? curr->content += (i + 1)
        : ft_strclr(curr->content);
    return (1);
}


int         ft_copyuntil(char **dst, char *src, char c)
{
    int     i;
    int     count;
    int     pos;

    i = -1;
    count = 0;
    while (src[++i])
        if (src[i] == c)
            break ;
    pos = i;
    if (!(*dst = ft_strnew(i)))
        return (0);
    while (src[count] && count < i)
    {
        if (!(*dst = ft_strjoinch(*dst, src[count])))
            return (0);
        count++;
    }
    return (pos);
}

char    *ft_strjoinch(char const *s1, char c)
{
    char    *new_str;
    size_t  i;
    size_t  s1_len;

    if (!s1 || !c)
        return (NULL);
    s1_len = ft_strlen(s1);
    new_str = ft_strnew(s1_len + 1);
    if (!new_str)
        return (NULL);
    i = -1;
    while (++i < s1_len)
        *(new_str + i) = *(s1 + i);
    *(new_str + i) = c;
    return (new_str);
}