#include "get_next_line.h"

int    ft_strlen(char *str)
{
    int    i = 0;

    while (str[i])
        i++;
    return (i);
}

char    *ft_strdup(char *s)
{
    char    *dup;
    int        len = 0;
    int        i = 0;

    len = ft_strlen(s) + 1;
    dup = (char *)malloc(len * sizeof(char));
    if (!dup)
        return (NULL);
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE];
    static int    pos;
    static int    size_read;
    char        line[70000];
    int            i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (pos >= size_read)
        {
            size_read = read(fd, buffer, BUFFER_SIZE);
            pos = 0;
            if (size_read == 0)
                break ;
        }
        line[i++] = buffer[pos++];
        if (buffer[pos] == '\n')
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (0);
    return (ft_strdup(line));
}

int    main(void)
{
    int    fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
}
