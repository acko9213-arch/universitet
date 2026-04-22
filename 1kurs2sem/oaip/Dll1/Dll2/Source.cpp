#include "pch.h"

#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

extern "C" {
    int* addArrMemory(int n) {
        return new int[n];
    }
    void addRandomNumToArr(int* arr, int n) {
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100;
    }
    void showArrElements(int* arr, int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    int findMaxElemInArr(int* arr, int n) {
        int max = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > max) max = arr[i];
        return max;
    }
    void deleteArr(int* arr) {
        delete[] arr;
    }
}
