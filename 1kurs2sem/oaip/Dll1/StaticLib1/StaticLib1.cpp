// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

#include "framework.h"
#include "Header2.h"
#include <iostream>
#include <ctime>

namespace MATRIXLIB {

    int init(int mat[10][10], int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = rand() % 10;
            }
        }
        return 0;
    }

    int view(int mat[10][10], int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << mat[i][j] << "  ";
            }
            std::cout << std::endl;
        }
        return 0;
    }

    int multiply(int A[10][10], int B[10][10], int res[10][10], int r1, int c1, int c2) {
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                res[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return 0;
    }

    int det(int mat[10][10], int n) {
        int d = 0;
        int submat[10][10];

        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x) continue;
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }

            if (x % 2 == 0) {
                d += mat[0][x] * det(submat, n - 1);
            }
            else {
                d -= mat[0][x] * det(submat, n - 1);
            }
        }
        return d;
    }

}
