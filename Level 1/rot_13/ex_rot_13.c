#include <unistd.h>

void rot_13(char *str)
{
	int i;
	char c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = (str[i] - 'a' + 13) % 26 + 'a';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			c = (str[i] - 'A' + 13) % 26 + 'A';
		else
			c = str[i];
		write (1, &c, 1);
		i++;
	}
	write (1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}