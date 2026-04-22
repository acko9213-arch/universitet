#include <iostream>
#include <string>
char knig[50][200];
using namespace std;


void dobav(register int i)
{
    int y;
    char dob[200];
    cout << "Вы хотите добавить книгу в учет взятых книг? 1-ДА;2-НЕТ"<<endl;
    cin >> y;
    static int pod=0;
    switch (y) {
    case 1:  cout << "Введите название взятой книги:";
        cin.ignore(); 
        fgets(knig[i], 200, stdin);
        
        i++;
        
         pod++; cout << "ID книги:" << i  <<endl<< "Количество книг в библиотеке:" << pod << << <<endl; 
        dobav(i);
        break;

    case 2:cout << "Досвидания!!!"; break;
    default:
        cout << "Неверный ввод, попробуйте еще раз." << endl;
        dobav(i);
        break;
    }
}
int main()
{
    setlocale(LC_CTYPE, "russian");
    
    register int i = 0;
  
  
    dobav(i);




    return 0;
}