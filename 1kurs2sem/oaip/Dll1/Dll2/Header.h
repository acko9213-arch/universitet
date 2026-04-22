#pragma once

#ifdef _WIN32
#ifdef ST
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT
#endif

extern "C" {
    DLL_EXPORT int* addArrMemory(int n);
    DLL_EXPORT void  addRandomNumToArr(int* arr, int n);
    DLL_EXPORT void  showArrElements(int* arr, int n);
    DLL_EXPORT int   findMaxElemInArr(int* arr, int n);
    DLL_EXPORT void  deleteArr(int* arr);
}