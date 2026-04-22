#include "Header2.h"
#include <iostream>
using namespace std;

int main() {
	int matrix1[10][10], matrix2[10][10], result[10][10];
	int a = 10, b = 8;
	MATRIXLIB::init(matrix1, a, b);
	MATRIXLIB::init(matrix2, b, a);
	cout << "matrix 1" << endl;
	MATRIXLIB::view(matrix1, a, b);
	cout << "matrix 2" << endl;
	MATRIXLIB::view(matrix2, b, a);
	MATRIXLIB::multiply(matrix1, matrix2, result, a, b, a);
	cout << "result matrix" << endl;
	MATRIXLIB::view(result, a, a);
	cout << "result matrix det" << endl;
	cout << MATRIXLIB::det(result, a);
	return 0;
}