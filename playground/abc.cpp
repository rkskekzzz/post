#include <iostream>

int main()
{
	double money = 1;
	double i;
	double k;
	for(k = 3 ; k < 10; k++)
	{
		for (i = 0; i < 10000; i++)
		{
			if ((int)(((money + i) / k) * 10) % 10 == 9 )
				std::cout << "people" << k << ", add money = " << i << std::endl;
		}
	}
}
