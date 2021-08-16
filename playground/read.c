#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char buf[200];

	int bufsize = 100;
	int readsize;

	while ((readsize = read(STDIN_FILENO, buf, bufsize)) > 0)
	{
		printf("%s\n", buf);
		printf("test\n");
	}
	printf("hello\n");
	return (0);
}
