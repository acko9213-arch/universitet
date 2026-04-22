#include <iostream>

using namespace std;
double f1(double x)
{
	return (sin(x)+0.3);
}
double f2(double x)
{
	return (pow(x, 3) + x - 2);
}
double f(double a, double b, double (*fun)(double))
{
	double e = 0.001;
	
	double x=0;
	

	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if (fun(a)*fun(x) <= 0) {
			b = x;
		}
		else a = x;
	}
	return x;
}
int main()
{
	setlocale(LC_CTYPE, "russian");
	cout << "Введите координату начала и конца отрезка:" << endl << "a="; double a;
	
	
	cin >> a;
	double b;
	cout << "b=";
	cin >> b;
	cout << "X первого уравнения:" << f(a, b, f1) <<endl;
	cout << "X второго уравнения:" << f(a, b, f2);
	
	return 0;
}