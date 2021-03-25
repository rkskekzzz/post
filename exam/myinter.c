#include <unistd.h>

int ft_strchr(char *str, char ch)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (1);
		++i;
	}
	return (0);
}

void ft_inter(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]))
			write(1, &s1[i], 1);
		++i;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
