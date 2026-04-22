#include "pch.h"
#include "stroka.h"
#include <cctype>

namespace stroks {
    int dlina(char a[]) {

        int i = 0;
        while (a[i] != '\0')
        {
            i++;
        }
        return i;
    }

    char* konk(char a[], char b[]) {
        int i = dlina(a);
        int d = dlina(b);

        char* arr = new char[i + d + 1];

      
        for (int j = 0; j < i; j++) {
            arr[j] = a[j];
        }

       
        for (int j = 0; j < d; j++) {
            arr[i + j] = b[j]; 
        }

        arr[i + d] = '\0';

        return arr;
    }

    bool palin(char a[]) {
        bool da = true;
        for (int i = 0, j = dlina(a) - 1; i < (dlina(a) - 1) / 2; i++, j--)
        {
            if (tolower((unsigned char)a[i]) != tolower((unsigned char)a[j]))
            {
                da = false;
            }
        }
        return da;
    }
}