#include <stdio.h>

int *singleton()
{
	static int val = 42;

	return (&val);
}

int main(void)
{
	printf("val : %d\n", *singleton());
	*singleton() += 42;
	printf("val : %d\n", *singleton());


	return (0);
}
