#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *datas = malloc(1);
	
	datas[10] = 10;
	printf("%d\n", datas[50]);
	printf("size : %lu\n", sizeof(datas));

	for (int i = 0 ; i < 1000 ; ++i)
		printf("for : %x\n", datas[i]);
	return 0;
}
