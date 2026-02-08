#include <iostream> 

using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int A, B, C, D;
	cout << "¬ведите A:";
	cin >> A;
	cout << "¬ведите B:";
	cin >> B;
	cout << "¬ведите C:";
	cin >> C;
	cout << "¬ведите D:";
	cin >> D;
	
	if (A % 2 == 0 or B % 2 == 0 or C % 2 == 0 or D % 2 == 0)  { cout << "—реди заданных чисел есть четное число."; }
	
	else cout << "—реди заданных чисел нет четноых чиссел.";
	return 0;
}