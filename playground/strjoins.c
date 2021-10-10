#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*strjoin(char *s1, char *s2)
{
	int		n;
	int		m;
	char	*ret;

	n = strlen(s1);
	m = strlen(s2);
	ret = (char *)malloc(n + m + 1);
	if (!ret)
		exit(12);
	bzero(ret, n + m + 1);
	if (s1)
		memcpy(ret, s1, n);
	if (s2)
		memcpy(ret + n, s2, m);
	ret[n + m] = 0;
	return (ret);
}

char* str_joins(char **strs, int n)
{
	char *temp;
	char *output;
	int idx;

	idx = 0;
	output = strdup(strs[idx]);
	while (++idx < n)
	{
		temp = strdup(output);
		free(output);
		output = strjoin(temp, strs[idx]);
		free(temp);
	}
	return (output);
}

int main(void)
{
	char *test;
	char *comma;
	char **arg;

	test = "hi";
	comma = ",";
	arg = (char *[3]){
		test,
		comma,
		test
	};
	char *output = str_joins(arg, 3);
	printf("%s\n", output);
	while (1)
		;
	return (0);
}
