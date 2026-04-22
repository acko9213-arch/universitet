#include "stdafx.h"
#include "Dictionary.h"




#if (defined(TEST_CREATE_01)   + defined(TEST_CREATE_02)  + \
     defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04)+ \
     defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06)+ \
     defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08)+ \
     defined(TEST_DICTIONARY)) > 1
#error "Ошибка: одновременно определено более одного тестового макроса!"
#endif

Dictionary::Instance Dictionary::Create(const char name[DICTNAMEMAXSIZE], const int size)
{

    if (strlen(name) > DICTNAMEMAXSIZE)
    {
        throw THROW01;
    }
    if (DICTMAXSIZE < size || size <= 0)
    {
        throw THROW02;
    }

    Entry* arr1 = new Entry[size];

    for (int i = 0; i < size; i++) {
        arr1[i].id = 0;
        arr1[i].name[0] = '\0';
    }

    Dictionary::Instance SLOVAR = {
        "",
        DICTMAXSIZE,
       0,
        arr1
    };

    strcpy_s(const_cast<char*>(SLOVAR.name), DICTNAMEMAXSIZE, name);

    return SLOVAR;
}
void Dictionary::AddEntry(Dictionary::Instance& inst, Dictionary::Entry ed)
{


    if (inst.size >= inst.maxsize) throw THROW03;
    for (int i = 0; i < inst.size; i++)
    {
        if (inst.dictionary[i].id == ed.id)
        {
            throw THROW04;
        }
    }
    inst.dictionary[inst.size].id = ed.id;
    strcpy_s(inst.dictionary[inst.size].name, ENTRYNAMEMAXSIZE, ed.name);
    inst.size++;
}
void Dictionary::DelEntry(Dictionary::Instance& inst, int id)
{
    if (id <= 0 || inst.size < id)
    {
        throw THROW06;
    }
    for (int i = id - 1; i < inst.size - 1; i++)
    {
        inst.dictionary[i] = inst.dictionary[i + 1];
    }

    inst.size--;
}
void Dictionary::UpdEntry(Dictionary::Instance& inst, int id, Dictionary::Entry new_ed)
{
    int pos = -1;
    for (int i = 0; i < inst.size; i++)
    {
        if (inst.dictionary[i].id == id)
        {
            pos = i;
            break;
        }
    }


    if (pos == -1)
    {
        throw THROW07;
    }


    for (int i = 0; i < inst.size; i++)
    {
        if (i != pos && inst.dictionary[i].id == new_ed.id)
        {
            throw THROW08;
        }
    }


    inst.dictionary[pos].id = new_ed.id;
    strcpy_s(inst.dictionary[pos].name, ENTRYNAMEMAXSIZE, new_ed.name);
    inst.dictionary[pos].name[ENTRYNAMEMAXSIZE - 1] = '\0';
}
Dictionary::Entry Dictionary::GetEntry(Dictionary::Instance inst, int id)
{
    for (int i = 0; i < inst.size; i++)
    {
        if (inst.dictionary[i].id == id)
        {
            return inst.dictionary[i];
        }
    }
    throw THROW05;
}
void Dictionary::Print(Dictionary::Instance d)
{
    cout << "---------- " << d.name << " ----------" << endl;
    for (int i = 0; i < d.size; i++)
    {
        cout << i + 1 << " " << d.dictionary[i].name << endl;
    }
}
void Dictionary::Delete(Dictionary::Instance& d)
{

    delete[] d.dictionary;
    d.dictionary = nullptr;
    d.size = 0;
}
#ifdef TEST_CREATE_01
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    try
    {
        Dictionary::Instance d = Dictionary::Create("памавысуиепмкасувцчмк", 5);
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif

#ifdef TEST_CREATE_02
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
   
    try
    {

        Dictionary::Instance d = Dictionary::Create("Тест", 200);
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif



#ifdef TEST_ADDENTRY_03
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
  
    try
    {
        Dictionary::Instance d = Dictionary::Create("Тест", 2);
        Dictionary::AddEntry(d, { 1, "Первый" });
        Dictionary::AddEntry(d, { 2, "Второй" });

        Dictionary::AddEntry(d, { 3, "Третий" });
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif


#ifdef TEST_ADDENTRY_04
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
  try
    {
        Dictionary::Instance d = Dictionary::Create("Тест", 5);
        Dictionary::AddEntry(d, { 1, "Первый" });
        Dictionary::AddEntry(d, { 1, "Дубликат" });
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif


#ifdef TEST_GETENTRY_05
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    try
    {
        Dictionary::Instance d = Dictionary::Create("Тест", 5);
        Dictionary::AddEntry(d, { 1, "Первый" });

        Dictionary::Entry e = Dictionary::GetEntry(d, 99);
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif

#ifdef TEST_DELENTRY_06
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
   
    try
    {
        Dictionary::Instance d = Dictionary::Create("Тест", 5);
        Dictionary::AddEntry(d, { 1, "Первый" });

        Dictionary::DelEntry(d, 0);
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif

#ifdef TEST_UPDENTRY_07
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
 
    try
    {
        Dictionary::Instance d = Dictionary::Create("Тест", 5);
        Dictionary::AddEntry(d, { 1, "Первый" });
        Dictionary::UpdEntry(d, 99, { 2, "Новый" });
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif


#ifdef TEST_UPDENTRY_08
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    try
    {
        Dictionary::Instance d = Dictionary::Create("Тест", 5);
        Dictionary::AddEntry(d, { 1, "Первый" });
        Dictionary::AddEntry(d, { 2, "Второй" });
        Dictionary::UpdEntry(d, 1, { 2, "Дубликат" });
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif


#ifdef TEST_DICTIONARY
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
   
    try
    {

        Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 10);
        Dictionary::Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веалкин" }, e3 = { 3,"Смелов" },
            e4 = { 4,"Урбанович" }, e5 = { 5,"Сидорчук" }, e6 = { 6,"Козлов" },
            e7 = { 7,"Морозов" };
        Dictionary::AddEntry(d1, e1);
        Dictionary::AddEntry(d1, e2);
        Dictionary::AddEntry(d1, e3);
        Dictionary::AddEntry(d1, e4);
        Dictionary::AddEntry(d1, e5);
        Dictionary::AddEntry(d1, e6);
        Dictionary::AddEntry(d1, e7);


        Dictionary::Entry found = Dictionary::GetEntry(d1, 4);
        cout << "GetEntry(4): " << found.name << endl;

        Dictionary::DelEntry(d1, 2);

        Dictionary::Entry upd1 = { 8, "Гурин" };
        Dictionary::UpdEntry(d1, 3, upd1);

        Dictionary::Print(d1);
        Dictionary::Instance d2 = Dictionary::Create("Студенты", 10);
        Dictionary::Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" },
            s4 = { 4,"Кузнецов" }, s5 = { 5,"Новиков" }, s6 = { 6,"Фёдоров" },
            s7 = { 7,"Михайлов" };
        Dictionary::AddEntry(d2, s1);
        Dictionary::AddEntry(d2, s2);
        Dictionary::AddEntry(d2, s3);
        Dictionary::AddEntry(d2, s4);
        Dictionary::AddEntry(d2, s5);
        Dictionary::AddEntry(d2, s6);
        Dictionary::AddEntry(d2, s7);
        Dictionary::Entry upd3 = { 3, "Николаев" };
        Dictionary::UpdEntry(d2, 3, upd3);

        Dictionary::Print(d2);

        Dictionary::Delete(d1);
        Dictionary::Delete(d2);
    }
    catch (const char* e)
    {
        cout << "Исключение: " << e << endl;
    }
    system("pause");
    return 0;
}
#endif