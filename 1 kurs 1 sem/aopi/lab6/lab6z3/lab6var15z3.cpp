#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float z, y = 0.4, w, t = 3, j[] = {0.2,-1.6,9.4};


	int a = 1;
	do
	{
		
		for (int n = 0; n < 4; n++)
		{

			z = sqrt(t * a + y) + 4 * exp(-2 * j[n]);

			w = log(0.4 * y) / (7 * a - z);


			
			

			cout << "Значение z=" << z << ",";
			cout << "Значение w=" << w << endl;
			

		}
		t = t + 0.2;

	} while (t < 4.1);

	return 0;

}

