#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	char	*dup;

	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	pos;
	static int	size;
	char		line[70000];
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (pos >= size)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (size == 0)
				break;
		}
		line[i++] = buffer[pos++];
	}
	return (ft_strdup(line));
}

int	main (void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));

	return (0);
}