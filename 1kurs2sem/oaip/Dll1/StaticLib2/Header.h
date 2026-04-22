
#pragma once

#ifndef HEADER1_H
#define HEADER1_H


#define EXPORT 

extern "C" {
    EXPORT int* create_array(int size);
    EXPORT void init_array(int* arr, int size, int value);
    EXPORT int find_max(int* arr, int size);
    EXPORT void print_array(int* arr, int size);
    EXPORT void delete_array(int*& arr);
}

#endif