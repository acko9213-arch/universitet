#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");

    if (file1.fail() || file2.fail()) {
        cout << "\n Ошибка открытия файла." << endl;
        return 1;
    }

    char buff[100], word1[20], word2[20];
    int max = -1;
    int Num = 0;
    int global = 0;

    while (file1.getline(buff, 100)) {
        bool da = false;

        
        for (int i = 0; buff[i] != '\0'; i++) {
            if (buff[i] == ' ') continue;

            
            int j = 0;
            int i1 = i;
            while (buff[i1] != ' ' && buff[i1] != '\0') {
                word1[j++] = buff[i1++];
            }
            word1[j] = '\0';

            
            for (int k = i1; buff[k] != '\0'; k++) {
                if (buff[k] == ' ') continue;

                int m = 0;
                int i2 = k;
                while (buff[i2] != ' ' && buff[i2] != '\0') {
                    word2[m++] = buff[i2++];
                }
                word2[m] = '\0';

                if (strcmp(word1, word2) == 0) {
                    da = true;
                    break;
                }
                k = i2 - 1; 
            }

            if (da) break;
            i = i1 - 1; 
        }

        if (da) {
            file2 << buff << endl;
        }

        
        for (int n = 0; buff[n] != '\0'; n++) {
            if (buff[n] == ' ') continue;

            global++; 
            int nu = 0;
            while (buff[n] != ' ' && buff[n] != '\0') {
                if (buff[n] >= '0' && buff[n] <= '9') {
                    nu++;
                }
                n++;
            }

            if (nu> max) {
                max = nu;
                Num = global;
            }
            if (buff[n] == '\0') break;
        }
    }

    if (Num > 0) {
        cout << "Номер слова с макс. кол-вом цифр: " << Num << endl;
    }
    else {
        cout << "Цифры в словах не найдены." << endl;
    }

    file1.close();
    file2.close();
    return 0;
}