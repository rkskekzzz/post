#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
int main() {
	struct timeval  tv;
	double begin, end;

	// 시작하는 시간 받아오기
	gettimeofday(&tv, NULL);
	begin = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;

	// 시간 측정을 진행할 부분
	usleep(1500000);

	// 끝나는 시간 받아오기
	gettimeofday(&tv, NULL);
	end = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;

	// 출력
	printf("Execution time %f\n", (end - begin) / 1000);
	return (0);
}
