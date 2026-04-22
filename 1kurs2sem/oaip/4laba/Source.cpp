#include <iostream>
#include <cstdio>
#include <cctype>
#include <Windows.h>
using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "russian");
    bool da = true;
     static int glas=0, sogl=0;
    char str[200],glasn[]="уеыаоэ€июeyuioa";
    char* buffer = str;
    cout << "¬ведите строку:";
    fgets(str,200,stdin);
    

    
    for (int i = 0; *(buffer + i) != '\0'; i++)
    {
        da = true;
        if (isalpha(unsigned char(*(buffer + i))))
        {
           
            for (int j = 0; j < 16; j++)
            {
                
               (*(buffer + i))= tolower(*(buffer + i));
                if (*(glasn + j) == *(buffer + i))
                {
                    glas++;da=false;
                }
                
            }
            if (da) {
                sogl++;
            }
        
        }
    }
    cout << "„исло гласных:" << glas << endl << "„исло согласных:" << sogl;
    return 0;
}