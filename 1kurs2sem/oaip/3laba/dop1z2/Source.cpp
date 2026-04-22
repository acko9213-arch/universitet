#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cctype>  

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    char input[1024];
    cout << "Enter a string: ";
    cin.getline(input, 1024);

    
    ofstream outFile("data.txt");
    outFile << input;
    outFile.close();

    
    ifstream inFile("data.txt");
    char word[256];

    cout << "Odd numbers: ";
    while (inFile >> word) {
      
        if (isdigit(word[0]) || (word[0] == '-' && isdigit(word[1]))) {
            int number = atoi(word); 

            if (number % 2 != 0) {
                cout << number << " ";
            }
        }
    }
    cout << endl;

    inFile.close();
    return 0;
}