#include <iostream>
#include <stdio.h>
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	using namespace std;
	
	int i = 0, s = 0, n = 0, sz=0, size = 0, j; char str[256];
	cout << "¬ведите строку:";
	gets_s(str);

	while (str[sz] != '\0')
	{
		sz++;
	}


	for (j=0; j < sz - size; j++)
	{
		for (i; i < sz; i++)
		{
			if (str[i] == '"')
			{
				s = i;
				break;
			}

		}

		for (i = i + 1; i < sz; i++)
		{
			if (str[i] == '"')
			{
				n = i; size = n - s + 1; break;
			}
		}

		i = s;
		if (str[s] == '"') {
			for (i; i + size < sz; i++)
			{
				str[i] = str[i + size];

			}
			sz -= size;
			str[sz] = 0;

			
		}
		
		
	}
	cout << endl;
	for (i = 0; str[i] != 0; i++)
	{
		cout << str[i];

	}
}