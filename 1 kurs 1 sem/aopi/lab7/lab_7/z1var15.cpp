#include <iostream>
#include <cmath>
int main()
{
	float s = 1.1, x = -4e-3, j = 4, b, z;

	while (j < 7.1)
	{
		b = 12 * s - exp(-s / 2) * (x - j);
		if (b < 1.5) { z = sqrt(-2 * x * j) + b; }
		else if (b >= 1.5) { z = abs(-13 * x * j) + b; }

		std::cout << "b=" << b << " z=" << z << std::endl;
		j = j + 0.5;
	}
	return 0;
}