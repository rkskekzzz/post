#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 쓰레드 함수
void *test(void *data)
{
    int i;
    int a = *(int *)data;
    printf("data -> : %d\n", a);
    for (i = 0; i < 1000000; i++)
    {
        printf("%d\n", i*a);
    }
    return (void *)(size_t)(i * 100);
}

int main()
{
    int a = 100;
    pthread_t thread_t;
    int status;

    // 쓰레드를 생성한다.
    if (pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }

		/* < 테스트 1 >
    ** 쓰레드가 종료되기를 기다린후
    ** 쓰레드의 리턴값을 출력한다.
    ** pthread_join(thread_t, (void **)&status); <- 테스트시 주석 해제
		*/
    // pthread_join(thread_t, (void **)&status); // <- 테스트시 주석 해제
		/* < 테스트 2 >
		** 쓰레드가 실행되는 도중에 중단시키면 어떤 일이 벌어지는지 확인한다.
    ** usleep(1);  <- 테스트시 주석 해제
		*/
    usleep(1); //  <- 테스트시 주석 해제

		/* < 결과 출력 >
		** pthread_join함수를 사용하면, status에는 쓰레드가 실행시킨 함수의 리턴값이 들어간다
		** 만약 2번 테스트로 중간에 쓰레드를 종료시키면 비어있는 값이 저장된다.
		*/
    printf("Thread End %d\n", status);
    return 1;
}
