#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float x, t ,q=0;
	std::cout << "¬ведите число t = ";
	std::cin >> t;

	q = q+ t;
	for (int i = 1; i < 7; i++)
	{
		std::cout << "¬ведите " << i << " число x = ";
		std::cin >> x;
		q =  q + ((x + 1) / x);
	}
	std::cout << q;
return 0;
}