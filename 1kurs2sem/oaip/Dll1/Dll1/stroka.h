#pragma once
#ifdef _WIN32
#  ifdef ST
#    define DLL_EXPORT __declspec(dllexport)
#  else
#    define DLL_EXPORT __declspec(dllimport)
#  endif
#else
#  define DLL_EXPORT
#endif

namespace stroks {
    DLL_EXPORT char* konk(char a[], char b[]);
    DLL_EXPORT bool palin(char a[]);
    DLL_EXPORT int dlina(char a[]);
}