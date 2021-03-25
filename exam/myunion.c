#include <unistd.h>

int check(char *str, char ch, int idx)
{
	int i;

	i = 0;
	while (i < idx)
	{
		if (str[i] == ch)
			return (0);
		++i;
	}
	return (1);
}

void ft_union(char *s1, char*s2)
{
	int i;
	int len;

	i = 0;
	while(s1[i])
	{
		if (check(s1, s1[i], i))
			write(1, &s1[i], 1);
		++i;
	}
	len = i;
	i = 0;
	while(s2[i])
	{
		if (check(s1, s2[i], len))
			if (check(s2, s2[i], i))
				write(1, &s2[i], 1);
		++i;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
