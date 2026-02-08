#include <iostream>
#include <stdio.h>
#include <Windows.h>
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_CTYPE, "russian");
	using namespace std;

	int i = 0, s = 0, n = 0, sz = 0, size = 0, j=0; char str[256];
	cout << "Введите строку:";
	gets_s(str);

    while (str[j] != '\0')
    {
        if (str[j] != ' ')
        {
            i = j;
            s = 0; 
            n = 0; 

          
                while (str[i] != ' ' && str[i] != '\0')
                {
                    s++;
                    if (str[i] == '1') n++;
                    i++;
                }
                if (str[i+1] == ' ' || str[i+1] !='\0')
                {
                    if (s % 2 != 0)
                    {
                        size += n; 
                    }
                 
                }
                j = i;
        }
        else
        {
            j++;
        }   
    }
	cout << endl;
	if (size == 0)
	{
		cout << "Нет единиц в строках с нечетными символами ";
	}
	else
	{
		cout << "Количество единиц в строках с нечетными символами" << size;
	}

	
}