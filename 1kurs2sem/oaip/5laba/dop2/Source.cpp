#include <iostream>
#include <string>
#include <regex>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    cout << "¬ведите текст:";
    getline(cin, text);
    regex word("[а-€ј-яa-zA-Z]+");
    smatch match;

    cout << "\n—писок найденных слов:" << endl;

    
    while (regex_search(text, match, word)) {
        cout << "- " << match[0] << endl;   
        text = match.suffix().str();
    }

    return 0;
}