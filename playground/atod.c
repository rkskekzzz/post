#include <stdio.h>
#include <math.h>

int ft_isdigit(char c)
{
	return (c >= '0' && c<= '9');
}

double ft_atod(char *line)
{
	double num;
	int sign;
	char *pos;

	pos = 0;
	sign = 1;
	num = 0;
	if(*line == '-')
	{
		sign = -1;
		++(line);
	}
	while(ft_isdigit(*line) || *line == '.')
	{
		if (*line == '.')
			pos = (line + 1);
		else
			num = num * 10 + (*line - '0');
		++(line);
	}
	// if (!pos)
		// return (num * sign);
	return (num / pow(10, line - pos) * sign) ;
}

int main()
{
	printf("[10 :%f]\n", ft_atod("10"));
	printf("[100 :%f]\n", ft_atod("100"));
	printf("[10000 :%f]\n", ft_atod("10000"));
	printf("[-3.751 :%f]\n", ft_atod("-3.751"));

}
