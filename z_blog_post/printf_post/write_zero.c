#include <unistd.h>
#include <stdio.h>


void pf_utils_put0x(char c, int len)
{
	write(1, "0", !(!len));
	--len;
	if (c== 'x' || c == 'p')
		write(1, "x", len);
	else
		write(1, "X", len);
}

int main()
{
	//pf_utils_put0x('p', 2);
	printf("%#04X", 42);
}
