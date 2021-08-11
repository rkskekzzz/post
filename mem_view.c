#include "stdio.h"

int main()
{
	void	*ptr;
	int	*i;

	ptr = 0x7fa3a8c17880;
	i = (int *)ptr;
	printf(" I : %d\n", *i);
}
