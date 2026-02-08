#include <iostream>
void baby(int* p, int b);
int main() 
{
	int A[10] = { 1,-9,3,5,9,-3,-4,-7,-1,-3 }, min = A[0];
	baby(A,min);
	return 0;
}
void baby(int* p, int min)
{
	int b;
	for (int i = 0; i < 10; i++)
	{
		if (p[i] < min)
		{
			min = p[i];
			b = i;
		}
	}
	min = 0;
	for (int i = b + 1; i < 10; i++)
	{
		if (p[i] < 0)
		{
			min++;
		}
	}
	std::cout << min;
}