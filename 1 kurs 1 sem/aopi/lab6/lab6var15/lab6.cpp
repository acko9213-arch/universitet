#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float z, y = 0.4, w, t = 5e+5;
	 
	 
	 int j[] = { 5,3,1,7,3 }, a = 1;
	for ( int n = 0; n<5; n++)
	{
		
		
		z = sqrt(t * a + y) + 4 * exp(-2 * j[n]);

		w = log(0.4 * y) / (7 * a - z);
		n = n + 1;
		cout << n << ")";
		
		
		cout << "Значение z=" << z << ",";
		cout << "Значение w=" << w << endl; n = n - 1;
		
	}
	

	return 0;

}

