#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h
int ret_errno(int errno);

int main(void)
{
	exit(ret_errno(12));
	return (0);
}

int ret_errno(int errno)
{
	printf("%s\n", strerror(errno));
	return (errno);
}
