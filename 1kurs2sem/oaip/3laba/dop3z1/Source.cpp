#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    int k;
    cout << "Ââåäèòå íîìåð íà÷àëüíîé ñòðîêè k: ";
    cin >> k;

    ifstream fin("FILE1.txt");
    ofstream fout("FILE2.txt");

    if (!fin.is_open()) {
        cout << "Îøèáêà: FILE1.txt íå íàéäåí!" << endl;
        return 1;
    }

    char line[1024];
    int currentLine = 1;

    
    while (fin.getline(line, 1024)) {
        if (currentLine >= k && currentLine <= k + 3) {
            fout << line << endl;
        }
        currentLine++;
    }
    fin.close();
    fout.close();

    
    ifstream f2("FILE2.txt");
    int vowelsCount = 0;
    char ch;

    
    const char* vowels = "aeiouyAEIOUYàå¸èîóûýþÿÀÅ¨ÈÎÓÛÝÞß";

    while (f2.get(ch)) {
        for (int i = 0; vowels[i] != '\0'; i++) {
            if (ch == vowels[i]) {
                vowelsCount++;
                break;
            }
        }
    }
    f2.close();

    cout << "Êîëè÷åñòâî ãëàñíûõ áóêâ â FILE2: " << vowelsCount << endl;

    return 0;
}