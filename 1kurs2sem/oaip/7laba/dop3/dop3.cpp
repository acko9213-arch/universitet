#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#define MAX 40

using namespace std;

static int i = 0;

struct Gorzhanin
{
    string fio;       // ФИО
    string datarozd;  // Дата рождения (формат: ДД.ММ.ГГГГ)
    string adres;     // Адрес
    char pol;         // Пол: 'м' или 'ж'
};

void vibor(struct Gorzhanin GOR[], int size);
void poisk(struct Gorzhanin GOR[], int size);
void del(struct Gorzhanin GOR[], int size);
void saveToFile(struct Gorzhanin GOR[], int size);
void loadFromFile(struct Gorzhanin GOR[], int size);
void vuvodvse(struct Gorzhanin GOR[], int size);
void vuvod(struct Gorzhanin GOR[], int size);

// Вспомогательная функция: извлечь год из строки "ДД.ММ.ГГГГ"
string getYear(const string& date)
{
    if (date.size() >= 10)
        return date.substr(7, 4);
    return "";
}

// Вывод одного горожанина
void printOne(struct Gorzhanin GOR[], int idx)
{
    cout << "--- Горожанин номер " << idx + 1 << " ---" << endl;
    cout << "ФИО:            " << GOR[idx].fio << endl;
    cout << "Дата рождения:  " << GOR[idx].datarozd << endl;
    cout << "Адрес:          " << GOR[idx].adres << endl;
    cout << "Пол:            " << GOR[idx].pol << endl;
}

// Добавить горожанина
void vvodel(struct Gorzhanin GOR[], int size)
{
    cin.clear();
    cin.ignore(10000, '\n');

    if (i >= size)
    {
        cout << "Массив заполнен!\n";
        vibor(GOR, size);
        return;
    }

    cout << "=== Добавление горожанина номер " << i + 1 << " ===" << endl;

    cout << "ФИО: ";
    getline(cin, GOR[i].fio);
    if (GOR[i].fio.empty()) {
        cout << "Вы ввели пустую строку. Выход в меню.\n";
        vibor(GOR, size); return;
    }

    cout << "Дата рождения (ДД.ММ.ГГГГ): ";
    getline(cin, GOR[i].datarozd);
    if (GOR[i].datarozd.empty()) {
        cout << "Вы ввели пустую строку. Выход в меню.\n";
        vibor(GOR, size); return;
    }

    cout << "Адрес: ";
    getline(cin, GOR[i].adres);
    if (GOR[i].adres.empty()) {
        cout << "Вы ввели пустую строку. Выход в меню.\n";
        vibor(GOR, size); return;
    }

    char p;
    cout << "Пол (м/ж): ";
    cin >> p;
    if (p != 'м' && p != 'ж' && p != 'M' && p != 'W' && p != 'm' && p != 'w')
    {
        cout << "Неверный пол. Введите 'м' или 'ж'. Выход в меню.\n";
        vibor(GOR, size); return;
    }
    GOR[i].pol = p;

    i++;
    cout << "Добавлено!\n";
    vibor(GOR, size);
}

// Вывод одного по номеру
void vuvod(struct Gorzhanin GOR[], int size)
{
    if (i == 0) {
        cout << "Список пуст.\n"; vibor(GOR, size); return;
    }

    int d, choice;
    cout << "Выберите номер горожанина (1-" << i << "): ";
    cin >> d;

    if (d < 1 || d > i)
    {
        cout << "Нет такого номера!\n1)Попробуйте ещё раз.\n2)Выйти в меню.\nВыбор: ";
        cin.clear(); cin.ignore(10000, '\n');
        cin >> choice;
        switch (choice) {
        case 1: vuvod(GOR, size); break;
        default: vibor(GOR, size); break;
        }
        return;
    }

    printOne(GOR, d - 1);
    cout << "Выведено!\n";
    vibor(GOR, size);
}

// Вывод всех
void vuvodvse(struct Gorzhanin GOR[], int size)
{
    if (i == 0) {
        cout << "Вы ещё не добавляли горожан.\n";
        vibor(GOR, size); return;
    }

    for (int z = 0; z < i; z++)
        printOne(GOR, z);

    cout << "Всего записей: " << i << endl;
    vibor(GOR, size);
}

// Удаление
void del(struct Gorzhanin GOR[], int size)
{
    if (i == 0) {
        cout << "Список пуст.\n"; vibor(GOR, size); return;
    }

    int choice;
    cout << "Введите номер горожанина для удаления (1-" << i << "): ";
    cin.clear(); cin.ignore(10000, '\n');
    cin >> choice;

    if (choice < 1 || choice > i)
    {
        int w;
        cout << "Нет такого номера!\n1)Попробуйте ещё раз.\n2)Выйти в меню.\nВыбор: ";
        cin.clear(); cin.ignore(10000, '\n');
        cin >> w;
        switch (w) {
        case 1: del(GOR, size); break;
        default: vibor(GOR, size); break;
        }
        return;
    }

    for (int l = choice - 1; l < i - 1; l++)
    {
        GOR[l].fio = GOR[l + 1].fio;
        GOR[l].datarozd = GOR[l + 1].datarozd;
        GOR[l].adres = GOR[l + 1].adres;
        GOR[l].pol = GOR[l + 1].pol;
    }
    i--;
    cout << "Удалено!\n";
    vibor(GOR, size);
}

// Поиск по году рождения (основная выборка по заданию)
void poisk(struct Gorzhanin GOR[], int size)
{
    if (i == 0) {
        cout << "Список пуст.\n"; vibor(GOR, size); return;
    }

    string god;
    cout << "Введите год рождения для поиска (ГГГГ): ";
    cin.clear(); cin.ignore(10000, '\n');
    getline(cin, god);

    bool found = false;
    for (int z = 0; z < i; z++)
    {
        if (getYear(GOR[z].datarozd) == god)
        {
            printOne(GOR, z);
            found = true;
        }
    }

    if (!found)
        cout << "Горожан с годом рождения " << god << " не найдено.\n";

    vibor(GOR, size);
}

// Сохранение в файл
void saveToFile(struct Gorzhanin GOR[], int size)
{
    if (i == 0) {
        cout << "Нечего сохранять.\n"; vibor(GOR, size); return;
    }

    remove("gorozhanin.txt");
    ofstream out("gorozhanin.txt");
    if (out.is_open())
    {
        out << i << endl;
        for (int z = 0; z < i; z++)
        {
            out << GOR[z].fio << endl;
            out << GOR[z].datarozd << endl;
            out << GOR[z].adres << endl;
            out << GOR[z].pol << endl;
        }
        out.close();
        cout << "Данные успешно сохранены в gorozhanin.txt!\n";
    }
    else
        cout << "Ошибка при открытии файла!\n";

    vibor(GOR, size);
}

// Загрузка из файла
void loadFromFile(struct Gorzhanin GOR[], int size)
{
    ifstream in("gorozhanin.txt");
    if (!in.is_open())
    {
        cout << "Файл не найден!\n"; vibor(GOR, size); return;
    }

    int count;
    in >> count;
    in.ignore();

    if (count > size)
    {
        cout << "В файле больше записей, чем размер массива. Загружено будет " << size << ".\n";
        count = size;
    }

    i = 0;
    for (int z = 0; z < count; z++)
    {
        getline(in, GOR[z].fio);
        getline(in, GOR[z].datarozd);
        getline(in, GOR[z].adres);
        string polStr;
        getline(in, polStr);
        GOR[z].pol = polStr.empty() ? ' ' : polStr[0];
        i++;
    }
    in.close();
    cout << "Данные загружены! Всего записей: " << i << endl;
    vibor(GOR, size);
}

// Главное меню
void vibor(struct Gorzhanin GOR[], int size)
{
    int choice;
    cout << "\n\t=== МЕНЮ: Горожане ===" << endl
        << "1. Добавить горожанина" << endl
        << "2. Вывести одного горожанина" << endl
        << "3. Вывести всех горожан" << endl
        << "4. Удалить горожанина" << endl
        << "5. Поиск по году рождения" << endl
        << "6. Сохранить в файл" << endl
        << "7. Загрузить из файла" << endl
        << "8. Выход" << endl
        << "Выбор: ";

    if (!(cin >> choice))
    {
        cout << "Неверный выбор. Попробуйте ещё.\n";
        cin.clear(); cin.ignore(10000, '\n');
        vibor(GOR, size); return;
    }

    switch (choice)
    {
    case 1: vvodel(GOR, size);    break;
    case 2: vuvod(GOR, size);     break;
    case 3: vuvodvse(GOR, size);  break;
    case 4: del(GOR, size);       break;
    case 5: poisk(GOR, size);     break;
    case 6: saveToFile(GOR, size);   break;
    case 7: loadFromFile(GOR, size); break;
    case 8: cout << "До свидания!\n"; break;
    default:
        cout << "Неверный выбор. Попробуйте ещё.\n";
        vibor(GOR, size); break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");

    struct Gorzhanin GOR[MAX];
    vibor(GOR, MAX);

    remove("gorozhanin.txt");
    return 0;
}