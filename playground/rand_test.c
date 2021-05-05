#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double	rand_num(int anti, int min, int max)
{
	if (anti == 0)
		return (0);
	if (min < max)
		return (min + (max - min) * rand_num(1,0,0));
	else
		return ((double)rand() / (double)RAND_MAX);
}

int main()
{
	for (int i = 0 ; i < 100 ; ++i)
	{
		printf("rand : %f\n", rand_num(1, 0, 0));
	}
}

//min + (max-min)*random_double(
