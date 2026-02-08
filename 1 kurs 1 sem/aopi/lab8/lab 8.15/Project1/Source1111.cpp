#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float a = -9999999, q = 0,x;
	for (int i = 1; i < 6; i++)
	{
		std::cout << "¬ведите " << i << " число x = "; 
		std::cin >> x;
		if (x <= a)
		{
			a = a;
		}
		else
		{
			a = x;
		}
		q = q + (a / (x+1));
	}
	std::cout << q;
	return 0;
}