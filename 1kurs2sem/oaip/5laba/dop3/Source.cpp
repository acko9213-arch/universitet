#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    cout << "¬ведите текст:" << endl;
    getline(cin, text);
    regex link(R"((https?://|www\.)[a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,6}(/[/\w\-\.]*)*)");
    smatch match;

    cout << "\n—писок найденных ссылок:" << endl;

    while (regex_search(text, match, link)) {
        cout << "- " << match[0] << endl;
        text = match.suffix().str();
    }


    return 0;
}