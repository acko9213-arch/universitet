#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    char buffer[256];
    FILE* old, * nov;
    int  k;
    errno_t err, err1;
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
    cout << "Введите строку с которой хотите начать выводить:";
    cin >> k;
    if (k <= 0 ) {
        cout << "Номер строки должен быть больше 0";
        return 1;
    }
    for (int i = 1; i < k; i++) {
        if (fgets(buffer, sizeof(buffer), old) == NULL) break;
    }
    for (int i = 0; i < 3; i++) {
        if (fgets(buffer, sizeof(buffer), old) != NULL) {
            fputs(buffer, nov);
        }
        else {
            break; 
        }
    }
            printf("Файл создан");
            fclose(old);
            fclose(nov);
    return 0;
}