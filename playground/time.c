#include <time.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	time_t start, end;

	time(&start);
	sleep(1.5);
	time(&end);

	printf("time = %f\n", (float)(end - start)); // 출력
	return (0);
}
