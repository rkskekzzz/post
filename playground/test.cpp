#include <vector>
#include <iostream>

int main()
{
	std::vector<int> a;

	a = std::vector(50, 0);
	a = std::vector(10, 1);
	for(size_t  i = 0 ; i < a.size(); ++i)
	{
		std::cout << a[i] << " ";
	}
}
