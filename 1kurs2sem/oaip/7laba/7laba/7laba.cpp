#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define MAX 40

static int i = 0;


using namespace std;
struct Prepodovateli
{

	string famprepod;
	string eks;
	string data;

};
void poisk(struct Prepodovateli PREP[], int size);
void vibor(struct Prepodovateli PREP[], int size);
void del(struct Prepodovateli PREP[], int size);
void loadFromFile(struct Prepodovateli PREP[], int size); void saveToFile(struct Prepodovateli PREP[], int size);
void vvodel(struct Prepodovateli PREP[], int size)
{
    static bool da = true;
    cin.clear();
    cin.ignore(10000, '\n');
    i++;
    if (i >= size)
    {
        cout << "Массив заполнен!\n"; vibor(PREP, size);
    }
    else
        cout << "Экзамен номер " << i << endl;
    cout << "Фамилия: ";      getline(cin,PREP[i - 1].famprepod);
    if (PREP[i-1].famprepod.empty()) {
        i--; da = false; cout << "Вы ввели пустую строчку\n";     
    }
    if (da)
    {

        cout << "Предмет: ";      getline(cin, PREP[i - 1].eks);
        if (PREP[i - 1].eks.empty()) {
            i--; da = false; cout << "Вы ввели пустую строчку\n";    
        }
    }
    if (da) {

        cout << "Дата экзамена: "; getline(cin, PREP[i - 1].data);
        if (PREP[i - 1].data.empty()) {
            i--; da = false; cout << "Вы ввели пустую строчку\n";    
        }
    }
    if (!da)
    {
        cout << "Выход в меню\n";    da = true; vibor(PREP, size);

    }
    else
    {
        cout << "Добавлено!\n"; vibor(PREP, size);
    }
}
void vuvod(struct Prepodovateli PREP[], int size)
{
    if (i == 0)
    {
        cout << "Нечего сохранять.\n"; vibor(PREP, size);
    }
    else
    {
        int d, choice;
        cout << "Выберете нужный вам экзамен:";
        cin >> d;

        if (d > i || d < 1)
        {



            cout << "Нет такого номера!\n1)Попробуйте ещё раз.\n2)Выйти в меню.\n" << "Выбор: "; cin.clear();
            cin.ignore(10000, '\n');
            cin >> choice;

            switch (choice) {
            case 1: { vuvod(PREP, size); break; }

            case 2: {
                vibor(PREP, size); break;
            default: {
            }
                   cout << "Неверный выбор. Выход в меню.";
                   vibor(PREP, size); break;
            }
            }

        }
        else
        {
            cout << "Экзамен номер " << d << endl;
            cout << "Фамилия: " << PREP[d - 1].famprepod << endl;
            cout << "Предмет: " << PREP[d - 1].eks << endl;
            cout << "Дата экзамена: " << PREP[d - 1].data << endl;

            cout << "Выведено!\n"; vibor(PREP, size);
        }
    }
}
void vuvodvse(struct Prepodovateli PREP[], int size)
{
    if (i == 0)
    {
        cout << "Вы ещё не записывали экзамены."<< endl;

    }
    else
    {
        for (int z = 0; z <= i - 1; z++)
        {
            cout << "Экзамен номер " << z + 1 << endl;
            cout << "Фамилия: " << PREP[z].famprepod << endl;
            cout << "Предмет: " << PREP[z].eks << endl;
            cout << "Дата экзамена: " << PREP[z].data << endl;


        }

        cout << "Выведено!\n"; vibor(PREP, size);
    }
}
void vibor(struct Prepodovateli PREP[],int size )
{
    int choice;
        cout << "\t=== МЕНЮ ===\n"
            << "1. Добавить преподавателя,экзамен,и дату экзамена.\n"
            << "2. Вывести один экзамен\n"
            << "3. Вывести все экзамены\n"
            << "4. Удалить преподователя\n"
            << "5. Поиск по фамилии\n"
            << "6. Сохранить в файл\n"
            << "7. Загрузить из файла\n"
            << "8. Выход\n"
            << "Выбор: ";
        
        if (!(cin >> choice))
        {
            cout << "Неверный выбор. Попробуйте ещё.\n"; cin.clear();
            cin.ignore(10000,'\n');
           
            vibor(PREP, size);
        }
        switch (choice) {
        case 1:  vvodel(PREP, size); break;
        case 2:   vuvod(PREP, size); break;
        case 3:  vuvodvse(PREP, size); break;
        case 4:     del(PREP, size); break;
        case 5: poisk(PREP, size); break;
        case 6:  saveToFile(PREP, size); break;
        case 7:  loadFromFile(PREP, size); break;
        case 8: cout << "До свидания!\n"; break;
        default: {
            cout << "Неверный выбор. Попробуйте ещё.";
            vibor(PREP, size); break;
        }
        }
}

void del(struct Prepodovateli PREP[], int size)
{
    if (i == 0)
    {
        cout << "Нечего сохранять.\n"; vibor(PREP, size);
    }
    else
    {
    int choice;
    cout << "Введите номер экзамена для удаления:"; cin.clear();
    cin.ignore(10000, '\n');
    cin >> choice;
    if (choice > i || choice < 1)
    {
        cout << "Нет такого номера!\n1)Попробуйте ещё раз.\n2)Выйти в меню.\n" << "Выбор: "; cin.clear();
        int w;
        cin.ignore(10000, '\n');
        cin >> w;
            switch (w) {
            case 1: { del(PREP, size); break; }

            case 2: {
                vibor(PREP, size); break;
            default: {

                cout << "Неверный выбор. Выход в меню.\n";
                vibor(PREP, size); break;
            }
            }
            }
        }
    else
    {
        for (int l = choice - 1; l < i; l++)
        {
            PREP[l].famprepod = PREP[l + 1].famprepod;
            PREP[l].eks = PREP[l + 1].eks;
            PREP[l].data = PREP[l + 1].data;
        }
        i--;
        cout << "Удалено!"<<endl; vibor(PREP, size);
    }
    }}
void poisk(struct Prepodovateli PREP[], int size)
{
    if (i == 0)
    {
        cout << "Нечего сохранять.\n"; vibor(PREP, size);
    }
    else
    {
        bool da = true;
        string fam;
        cout << "Введите фамилию нужного преподавателя: " << fam;
        cin.clear();
        cin.ignore(10000, '\n'); getline(cin, fam);
        for (int z = 0; z < i; z++)
        {
            if (PREP[z].famprepod == fam)
            {
                cout << "Экзамен номер " << z + 1 << endl;
                cout << "Фамилия: " << PREP[z].famprepod << endl;
                cout << "Предмет: " << PREP[z].eks << endl;
                cout << "Дата экзамена: " << PREP[z].data << endl;
                da = false;
            }
        }
        if (da)
        {
            cout << "Такого преподавателя нету.\n";
        }
        vibor(PREP, size);
    }
}
void saveToFile(struct Prepodovateli PREP[], int size)
{
    if (i == 0)
    {
        cout << "Нечего сохранять.\n"; vibor(PREP, size);
    }
    else
    {
        remove("database.txt");

        ofstream out("database.txt");
        if (out.is_open())
        {
            out << i << endl;
            for (int z = 0; z < i; z++)
            {
                out << PREP[z].famprepod << endl;
                out << PREP[z].eks << endl;
                out << PREP[z].data << endl;
            }
            out.close();
            cout << "Данные успешно сохранены в database.txt!\n";
        }
        else
        {
            cout << "Ошибка при открытии файла!\n";
        }
        vibor(PREP, size);
    }
}

void loadFromFile(struct Prepodovateli PREP[], int size)
{
    if (i == 0)
    {
        cout << "Нечего сохранять.\n"; vibor(PREP, size);
    }
    else
    {
        string buf;
        ifstream in("database.txt");
        if (in.is_open())
        {
            int buf1, g = 1;
            in >> buf1;
            in.ignore();
            for (int z = 0; z < buf1; z++)
            {
                cout << "Экзамен номер " << g << endl;

                getline(in, buf); cout << "Фамилия: " << buf << endl;
                getline(in, buf); cout << "Предмет: " << buf << endl;
                getline(in, buf);   cout << "Дата экзамена: " << buf << endl;
                g++;
            }
            in.close();
            cout << "Данные загружены! Всего записей: " << buf1 << endl;
        }
        else
        {
            cout << "Файл не найден!\n";
        }
        vibor(PREP, size);
    }
}
 int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");
	struct Prepodovateli PREP[40];
	vibor(PREP,MAX);
    remove("database.txt");
	return 0;
}









