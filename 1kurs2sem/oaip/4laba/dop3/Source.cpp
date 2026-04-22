#include <iostream>
using namespace std;

// 1. Глобальный массив для истории 
const int MAX = 100;
const int LENGTH = 256;
char history[MAX][LENGTH];
int сounter = 0;

void showHistory() {
    cout << "История операций: " << endl;
    for (int i = 0; i < MAX; i++) {
        if (history[i][0] == '\0') break;
        cout << i + 1 << ". " << history[i] << endl;
    }
}



int main() {
    setlocale(LC_CTYPE, "rus");

    // 2. Статические переменные для курсов
    static float BYN_USD = 0.31;
    static float BYN_RUB = 28.50;
    static float USD_BYN = 3.24;
    static float USD_RUB = 92.45;
    static float RUB_BYN = 0.035;
    static float RUB_USD = 0.011;

    int choice;
    while (true) {
        cout << "Доступные валюты: USD, RUB, BYN" << endl;
        cout << "1. BYN -> USD  |  2. BYN -> RUB" << endl;
        cout << "3. USD -> BYN  |  4. USD -> RUB" << endl;
        cout << "5. RUB -> BYN  |  6. RUB -> USD" << endl;
        cout << "7. История     |  8. Выход" << endl;
        cout << "Выберите вариант: ";
        

        if (!(cin >> choice)) {
            cout << "Неверный ввод!" << endl;
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        if (choice == 8) break;
        if (choice == 7) {
            showHistory();
            continue;
        }

        // 3. Локальная переменная для ввода суммы
        float amount;
        if (choice >= 1 && choice <= 6) {
            cout << "Введите сумму: ";
            cin >> amount;
        }
        else {
            cout << "Неверный ввод!" << endl;
            continue;
        }

        // 4. Регистровая переменная для промежуточных расчётов
        register float result = 0;
        const char* from = "";
        const char* to = "";

        switch (choice) {
        case 1: result = amount * BYN_USD; from = "BYN"; to = "USD"; break;
        case 2: result = amount * BYN_RUB; from = "BYN"; to = "RUB"; break;
        case 3: result = amount * USD_BYN; from = "USD"; to = "BYN"; break;
        case 4: result = amount * USD_RUB; from = "USD"; to = "RUB"; break;
        case 5: result = amount * RUB_BYN; from = "RUB"; to = "BYN"; break;
        case 6: result = amount * RUB_USD; from = "RUB"; to = "USD"; break;
        }
        printf("Результат: %.2f %s\n", result, to);
        snprintf(history[сounter], LENGTH, "%.2f %s -> %.2f %s", amount, from, result, to);
        сounter++;

    }
    return 0;
}