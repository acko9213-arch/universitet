#include <iostream>
int defaultparm(int a,int b,int c,int d,int f,int g =10,int h=20)
{
	return (a + b + c + d + f + g + h) / 7;
}
int main()
{
	int z = defaultparm(1, 2, 3, 4, 5);

	int b = defaultparm(1, 2, 3, 4, 5,6,7);

	return 0;

}

