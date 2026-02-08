
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float x, y = 0, w, t = 0.5;


	
	do
	{
		if (t > 2) {
			if (t == 2.5) {
				for (int i = 1; i < 6; i++)
				{
					cout << "¬ведите " << i << " число x = ";
					cin >> x;
					x = x + pow(x, 2);
				}
				y = x + t;
				cout << "y = " << y << " " << "при t = " << t << endl;
			}
			else { y = x + t; cout << "y = " << y << " " << "при t = " << t << endl;
			}
		}
		else
			if (t<=2)
			{
				y = cos(pow(t, 2));
				cout << "y = " << y <<" " << "при t = " << t << endl;
			}
		
		
		
		t = t + 0.5;

	} while (t < 3.1);

	return 0;

}