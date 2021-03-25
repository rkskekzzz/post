#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	char c;

	c = 'a';
	char d = ++++c;
	printf("%c", d);

}
