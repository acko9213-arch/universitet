#include <iostream>
#include <windows.h>
using namespace std;


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "Маршрут следования:" << endl;
    cout << "1)Выхожу из дома." << endl;
    cout << "2)Иду к Жлобинскому вокзалу." << endl;
    cout << "3)Сажусь на поезд." << endl;
    cout << "4)Выхожу на Минском вокзале." << endl;
    cout << "5)Иду к БГТУ." << endl;
 

    

    return 0;
}
