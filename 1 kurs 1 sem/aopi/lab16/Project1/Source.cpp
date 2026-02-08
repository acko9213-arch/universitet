#include <cctype>
#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;
void baby(char t[256])
{
	int i = 0;
	while (t[i] != ' ' && t[i] != '\0')
	{
		t[i] = toupper(t[i]);
		i++;
		
	}
	cout << t;
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	char t[256];
	cout << "Enter str:";
	gets_s(t);
	baby(t);
	
		
          
	
		
	
	return 0;
}
