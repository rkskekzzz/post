#include <stdio.h>

typedef struct s_info
{
	int a;
	int b;
}	t_info;

t_info init()
{
	t_info make;
	make.a = 1;
	make.b = 2;
	return (make);
}

int main(void)
{
	t_info test;
	test = init();
	printf("a : %d, b : %d", test.a, test.b);
	return (0);
}
