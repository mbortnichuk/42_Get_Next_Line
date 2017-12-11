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
    str->str = ft_strnew(0);
    str->fd = fd;
    str->next = *frst;
    *frst = str;
    return (str);
}

size_t    ft_is_n(char *str, int count, int bnlen)
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
        while (str[i] != '\n' && str[i++] != '\0' && bnlen == 1)
            counter++;
    }
    return (counter);
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