/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschula <<marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:44:27 by eschula           #+#    #+#             */
/*   Updated: 2025/03/19 14:45:28 by eschula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strdup(char *src)
{
    char *dest;
    int i;

    i = 0
    if(!src)
        return NULL;
    while(src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * i + 1);
    i = 0;
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_next_line(int fd)
{
    static int buffer_read;
    static int buffer_pos;
    static char buffer[BUFFER_SIZE];
    char        line[70000];
    unsigned int long i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            if (buffer_read <= 0)
                break;
            buffer_pos = 0;
        }
        while (buffer_pos < buffer_read)
        {
            line[i++] = buffer[buffer_pos++];
            if (line[i - 1] == '\n')
            {
                line[i] = '\0';
                return ft_strdup(line);
            }
        }
    }
    if (i > 0)
    {
        line[i] = '\0';
        return ft_strdup(line);
    }
    return NULL;
}
