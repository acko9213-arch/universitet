#include <iostream>
#include "Header.h"
using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");
    int n = 33;

    int* arr = addArrMemory(n);
    cout << "\nДобавление рандомных чисел в массив... "; addRandomNumToArr(arr, n);
    cout << "\nВывод полученного массива: "; showArrElements(arr, n);
    int max = findMaxElemInArr(arr, n);
    cout << '\n' << max;
    deleteArr(arr);

    return 0;
}