#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define MAX 40

static int i = 0;

using namespace std;

struct Sklad
{
    string naimenovanie; // Наименование товара
    double cena;         // Цена
    int kolichestvo;     // Количество
    int nadbavka;        // Процент торговой надбавки (5, 10, 15, 20, 35, 30)
};

void vibor(struct Sklad SKL[], int size);
void poisk(struct Sklad SKL[], int size);
void del(struct Sklad SKL[], int size);
void saveToFile(struct Sklad SKL[], int size);
void loadFromFile(struct Sklad SKL[], int size);
void vuvodvse(struct Sklad SKL[], int size);
void vuvod(struct Sklad SKL[], int size);

// Проверка допустимости надбавки
bool validNadbavka(int n)
{
    return (n == 5 || n == 10 || n == 15 || n == 20 || n == 35 || n == 30);
}

// Вывод одного товара
void printOne(struct Sklad SKL[], int idx)
{
    cout << "--- Товар номер " << idx + 1 << " ---" << endl;
    cout << "Наименование:    " << SKL[idx].naimenovanie << endl;
    cout << "Цена:            " << SKL[idx].cena << " руб." << endl;
    cout << "Количество:      " << SKL[idx].kolichestvo << " шт." << endl;
    cout << "Торговая надбавка: " << SKL[idx].nadbavka << "%" << endl;
}

// Добавить товар
void vvodel(struct Sklad SKL[], int size)
{
    cin.clear();
    cin.ignore(10000, '\n');

    if (i >= size)
    {
        cout << "Массив заполнен!\n"; vibor(SKL, size); return;
    }

    cout << "=== Добавление товара номер " << i + 1 << " ===" << endl;

    cout << "Наименование товара: ";
    getline(cin, SKL[i].naimenovanie);
    if (SKL[i].naimenovanie.empty()) {
        cout << "Вы ввели пустую строку. Выход в меню.\n";
        vibor(SKL, size); return;
    }

    cout << "Цена: ";
    if (!(cin >> SKL[i].cena) || SKL[i].cena < 0) {
        cout << "Неверное значение цены. Выход в меню.\n";
        cin.clear(); cin.ignore(10000, '\n');
        vibor(SKL, size); return;
    }

    cout << "Количество: ";
    if (!(cin >> SKL[i].kolichestvo) || SKL[i].kolichestvo < 0) {
        cout << "Неверное значение количества. Выход в меню.\n";
        cin.clear(); cin.ignore(10000, '\n');
        vibor(SKL, size); return;
    }

    cout << "Процент торговой надбавки (5, 10, 15, 20, 30, 35): ";
    if (!(cin >> SKL[i].nadbavka) || !validNadbavka(SKL[i].nadbavka)) {
        cout << "Недопустимое значение надбавки. Выход в меню.\n";
        cin.clear(); cin.ignore(10000, '\n');
        vibor(SKL, size); return;
    }

    i++;
    cout << "Добавлено!\n";
    vibor(SKL, size);
}

// Вывод одного по номеру
void vuvod(struct Sklad SKL[], int size)
{
    if (i == 0) {
        cout << "Список пуст.\n"; vibor(SKL, size); return;
    }

    int d, choice;
    cout << "Выберите номер товара (1-" << i << "): ";
    cin >> d;

    if (d < 1 || d > i)
    {
        cout << "Нет такого номера!\n1)Попробуйте ещё раз.\n2)Выйти в меню.\nВыбор: ";
        cin.clear(); cin.ignore(10000, '\n');
        cin >> choice;
        switch (choice) {
        case 1: vuvod(SKL, size); break;
        default: vibor(SKL, size); break;
        }
        return;
    }

    printOne(SKL, d - 1);
    cout << "Выведено!\n";
    vibor(SKL, size);
}

// Вывод всех
void vuvodvse(struct Sklad SKL[], int size)
{
    if (i == 0) {
        cout << "Вы ещё не добавляли товары.\n";
        vibor(SKL, size); return;
    }

    for (int z = 0; z < i; z++)
        printOne(SKL, z);

    cout << "Всего записей: " << i << endl;
    vibor(SKL, size);
}

// Удаление
void del(struct Sklad SKL[], int size)
{
    if (i == 0) {
        cout << "Список пуст.\n"; vibor(SKL, size); return;
    }

    int choice;
    cout << "Введите номер товара для удаления (1-" << i << "): ";
    cin.clear(); cin.ignore(10000, '\n');
    cin >> choice;

    if (choice < 1 || choice > i)
    {
        int w;
        cout << "Нет такого номера!\n1)Попробуйте ещё раз.\n2)Выйти в меню.\nВыбор: ";
        cin.clear(); cin.ignore(10000, '\n');
        cin >> w;
        switch (w) {
        case 1: del(SKL, size); break;
        default: vibor(SKL, size); break;
        }
        return;
    }

    for (int l = choice - 1; l < i - 1; l++)
    {
        SKL[l].naimenovanie = SKL[l + 1].naimenovanie;
        SKL[l].cena = SKL[l + 1].cena;
        SKL[l].kolichestvo = SKL[l + 1].kolichestvo;
        SKL[l].nadbavka = SKL[l + 1].nadbavka;
    }
    i--;
    cout << "Удалено!\n";
    vibor(SKL, size);
}

// Поиск по цене (выборка по заданию)
void poisk(struct Sklad SKL[], int size)
{
    if (i == 0) {
        cout << "Список пуст.\n"; vibor(SKL, size); return;
    }

    double cenaPoisk;
    cout << "Введите цену для поиска: ";
    cin.clear(); cin.ignore(10000, '\n');
    cin >> cenaPoisk;

    bool found = false;
    for (int z = 0; z < i; z++)
    {
        if (SKL[z].cena == cenaPoisk)
        {
            printOne(SKL, z);
            found = true;
        }
    }

    if (!found)
        cout << "Товаров с ценой " << cenaPoisk << " руб. не найдено.\n";

    vibor(SKL, size);
}

// Сохранение в файл
void saveToFile(struct Sklad SKL[], int size)
{
    if (i == 0) {
        cout << "Нечего сохранять.\n"; vibor(SKL, size); return;
    }

    remove("sklad.txt");
    ofstream out("sklad.txt");
    if (out.is_open())
    {
        out << i << endl;
        for (int z = 0; z < i; z++)
        {
            out << SKL[z].naimenovanie << endl;
            out << SKL[z].cena << endl;
            out << SKL[z].kolichestvo << endl;
            out << SKL[z].nadbavka << endl;
        }
        out.close();
        cout << "Данные успешно сохранены в sklad.txt!\n";
    }
    else
        cout << "Ошибка при открытии файла!\n";

    vibor(SKL, size);
}

// Загрузка из файла
void loadFromFile(struct Sklad SKL[], int size)
{
    ifstream in("sklad.txt");
    if (!in.is_open())
    {
        cout << "Файл не найден!\n"; vibor(SKL, size); return;
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
        getline(in, SKL[z].naimenovanie);
        in >> SKL[z].cena;
        in >> SKL[z].kolichestvo;
        in >> SKL[z].nadbavka;
        in.ignore();
        i++;
    }
    in.close();
    cout << "Данные загружены! Всего записей: " << i << endl;
    vibor(SKL, size);
}

// Главное меню
void vibor(struct Sklad SKL[], int size)
{
    int choice;
    cout << "\n\t=== МЕНЮ: Склад ===" << endl
        << "1. Добавить товар" << endl
        << "2. Вывести один товар" << endl
        << "3. Вывести все товары" << endl
        << "4. Удалить товар" << endl
        << "5. Поиск по цене" << endl
        << "6. Сохранить в файл" << endl
        << "7. Загрузить из файла" << endl
        << "8. Выход" << endl
        << "Выбор: ";

    if (!(cin >> choice))
    {
        cout << "Неверный выбор. Попробуйте ещё.\n";
        cin.clear(); cin.ignore(10000, '\n');
        vibor(SKL, size); return;
    }

    switch (choice)
    {
    case 1: vvodel(SKL, size);      break;
    case 2: vuvod(SKL, size);       break;
    case 3: vuvodvse(SKL, size);    break;
    case 4: del(SKL, size);         break;
    case 5: poisk(SKL, size);       break;
    case 6: saveToFile(SKL, size);  break;
    case 7: loadFromFile(SKL, size); break;
    case 8: cout << "До свидания!\n"; break;
    default:
        cout << "Неверный выбор. Попробуйте ещё.\n";
        vibor(SKL, size); break;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "rus");

    struct Sklad SKL[MAX];
    vibor(SKL, MAX);

    remove("sklad.txt");
    return 0;
}