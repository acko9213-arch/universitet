#include <cstdlib>
#include <iostream>

using namespace std;
void perevod(int num, ...)
{
	char buffer[33];
	int* p = &num;
	for (int i = 1; i <= num; i++)
	{
		
		cout << "Число в десятичной коде " << *(++p); 
		_itoa_s(*p, buffer, 2);
		cout <<" Число в двоичном коде " << buffer << endl;
		
	}
}
int main()
{ 
	setlocale(LC_CTYPE, "russian");
	perevod(5,4,2,8,9,9);
	
	return 0;
}