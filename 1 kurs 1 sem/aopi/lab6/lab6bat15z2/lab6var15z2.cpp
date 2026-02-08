#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float z, y = 0.4, w, t = 5e+5,j=1;


	int a = 1, n = 1;
	while(j<2.1)
	{


		z = sqrt(t * a + y) + 4 * exp(-2 * j);

		w = log(0.4 * y) / (7 * a - z);
		
		j = j + 0.2;

		cout << n << ")";
		n = n + 1;
		cout << "Значение z=" << z << ",";
		cout << "Значение w=" << w << endl;

	}


	return 0;

}

