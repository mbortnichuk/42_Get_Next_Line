#define CHECKMEM(v) if (!v) return (-1);

static t_gnl    *ft_multifd(t_gnl **frst, int fd)
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

static char    *ft_strjoin_ch(char const *s1, char c)
{
    char    *new;
    size_t  i;
    size_t  s1len;

    if (!s1 || !c)
        return (NULL);
    s1len = ft_strlen(s1);
    new = ft_strnew(s1len + 1);
    CHECKMEM(new);
    ft_strdel(new);
    // if (!new)
    //     return (NULL);
    // ft_strdel(&new);
    i = -1;
    while (++i < s1len)
        *(new + i) = *(s1 + i);
    *(new + i) = c;
    return (new);
}

static int         ft_copyuntil(char **dst, char *src, char c)
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
    ft_strdel(&dst);
    while (src[count] && count < i)
    {
        if (!(*dst = ft_strjoinch(*dst, src[count])))
            return (0);
        count++;
    }
    return (pos);
}

static t_list           *ft_get_valid_file(t_list **file, int fd)
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

}

// size_t    ft_is_n(char *str, int count, int bnlen)
// {
//     int        i;
//     size_t    counter;

//     i = 0;
//     counter = 0;
//     if (str)
//     {
//         while (str[i] && count == 1)
//             if (str[i++] == '\n')
//                 counter++;
//         while (str[i] != '\n' && str[i++] != '\0' && bnlen == 1)
//             counter++;
//     }
//     return (counter);
// }

char *ft_free_strjoin(char *s1, char *s2)
{
    char *temp;

    temp = s1;
    if (!(s1 = ft_strjoin(temp, s2)))
        return (NULL);
    free(temp);
    return (s1);
}

static int      ft_is_n(char *str)
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

char    *ft_trim_free(char *str)
{
    char    *tmp;
    int        i;
    int        a;

    i = 0;
    a = 0;
    tmp = ft_strnew(ft_strlen(str));
    while (str[i] != '\n')
        i++;
    i++;
    while (str[i])
        tmp[a++] = str[i++];
    ft_strdel(&str);
    tmp[a] = '\0';
    return (tmp);
}

int main()
{
    
}