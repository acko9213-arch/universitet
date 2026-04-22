#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <cctype>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char buffer[256];
    FILE* old, * nov;
    int  k;
    errno_t err, err1;
    char yk;
    err = fopen_s(&old, "F1.txt", "r");
    if (err != 0)
    {
        perror("ошибка открытия F1.txt");
        return EXIT_FAILURE;
    }
    err1 = fopen_s(&nov, "F2.txt", "w");
    if (err1 != 0)
    {
        perror("ошибка создания F2.txt");
        return EXIT_FAILURE;
    }
    while (fread((void*)&yk, sizeof(char), 1, old) == 1)
    {
        if (IsCharUpperA(yk))
        {
            fprintf(nov, "%c", yk);
        }
    }
    
   
    printf("Файл создан");
    fclose(old);
    fclose(nov);
    return 0;
}