#include <iostream>
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float d = 0, q = 0, y;


	for (int i = 1; i < 5; i++)
	{

		std::cout << "¬ведите " << i << " число x = ";

		std::cin >> y;
		if (y <= d)
			d = d;
		else
			d = y;


		q = q + (4*y+d);


	}

	std::cout << q;
	return 0;
}