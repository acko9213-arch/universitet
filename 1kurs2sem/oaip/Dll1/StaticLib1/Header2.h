#pragma once
#ifndef HEADER2_H  
#define HEADER2_H

#define EXPORT

namespace MATRIXLIB {
    EXPORT int init(int mat[10][10], int rows, int cols);
    EXPORT int view(int mat[10][10], int rows, int cols);
    EXPORT int multiply(int A[10][10], int B[10][10], int res[10][10], int r1, int c1, int c2);
    EXPORT int det(int mat[10][10], int n);
}

#endif

