#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    FILE* old, *nov;
    int k, size;
    errno_t err,err1;

    err=fopen_s(&old, "z1.txt", "r");
    if (err != 0)
    {
        perror("ошибка открытия z1.txt");
        return EXIT_FAILURE;
    }
    err1=fopen_s(&nov, "nov.txt", "w");
    if (err1 != 0)
    {
        perror("ошибка создания nov.txt");
        return EXIT_FAILURE;
    }
    if (old == NULL) return EXIT_FAILURE;

    fscanf_s(old, "%d", &size);

    printf("Размер матрицы %d. Введите k равный: (1-%d): ", size, size);
    cin >> k;

    fprintf(nov, "%d\n", 1);

    double d;
    for (int i = 0; i < size; i++) {
       for (int j = 1; j <= size; j++) {
            if (fscanf_s(old, "%lf", &d) != EOF) {
                if (j == k) {
                    fprintf(nov, "%.1f\n", d);
                }
            }
            else {
                printf("Не хватило чисел для матрицы  %dx%d\n", size, size);
                break;
            }
        }
    }
    printf("Столбец записан");
    fclose(old);
    fclose(nov);

    return 0;
}