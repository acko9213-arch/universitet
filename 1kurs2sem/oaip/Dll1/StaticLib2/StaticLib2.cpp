// StaticLib2.cpp : Определяет функции для статической библиотеки.
//
#include "framework.h"

//Создать динамическую библиотеку для работы с динамическими массивами целых чисел. 
// Библиотека должна предоставлять функции: создание динамического массива заданного размера, инициализация массива заданным значением, 
// нахождение максимального значения в массиве, удаление динамического массива и освобождения памяти, вывод элементов массива на экран

#include "Header.h"
#include <iostream>
extern "C" {
    int* create_array(int size) {
        if (size <= 0) return nullptr;
        return new int[size];
    }


    void init_array(int* arr, int size, int value) {
        if (arr == nullptr) return;
        for (int i = 0; i < size; ++i) {
            arr[i] = value;
        }
    }


    int find_max(int* arr, int size) {
        if (arr == nullptr || size <= 0) return 0;

        int max_val = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        return max_val;
    }


    void print_array(int* arr, int size) {
        if (arr == nullptr) {
            std::cout << "Array is empty (null)" << std::endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << (i == size - 1 ? "" : ", ");
        }
        std::cout << std::endl;
    }


    void delete_array(int*& arr) {
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr;
        }
    }
}
