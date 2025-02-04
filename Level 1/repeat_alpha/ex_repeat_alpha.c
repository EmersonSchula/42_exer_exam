#include <unistd.h>

void repeat_alpha(char *str)
{
	char repeat;

	while (*str)
	{

		if (*str >= 'a' && *str <= 'z')
			repeat = *str - 'a' + 1;
		else if (*str >= 'A' && *str <= 'Z')
			repeat = *str - 'A' + 1;
		else
			repeat = 1;

		while (repeat--)
			write(1, str, 1);

		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	return (0);
}