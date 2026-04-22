#include "stdafx.h"
#include "Dictionary.h"

#if (defined(TEST_CREATE_01)   + defined(TEST_CREATE_02)  + \
     defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04)+ \
     defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06)+ \
     defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08)+ \
     defined(TEST_DICTIONARY)) > 1
#error "Ошибка: одновременно определено более одного тестового макроса!"
#endif

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    try
    {
        #ifdef TEST_CREATE_01
        Dictionary::Instance d = Dictionary::Create("памавысуиепмкасувцчмк", 5);

#endif
      
#ifdef TEST_CREATE_02
        Dictionary::Instance d3 = Dictionary::Create("Студенты", 101);
#endif
#ifdef TEST_ADDENTRY_03
        Dictionary::Instance d = Dictionary::Create("Тест", 2);
    
        Dictionary::AddEntry(d, { 1, "Первый" });
        Dictionary::AddEntry(d, { 2, "Второй" });
        Dictionary::AddEntry(d, { 3, "Третий" });
#endif
      

#ifdef TEST_ADDENTRY_04
        Dictionary::Instance d = Dictionary::Create("Тест", 2);

        Dictionary::AddEntry(d, { 1, "Первый" });
        Dictionary::AddEntry(d, { 1, "Второй" });
#endif
      

   
#ifdef TEST_GETENTRY_05
        Dictionary::Instance d1 = Dictionary::Create("Тест", 2);
        Dictionary::Entry found1 = Dictionary::GetEntry(d1, 10);
#endif



      
#ifdef TEST_DELENTRY_06
        Dictionary::Instance d1 = Dictionary::Create("Тест", 2);
        Dictionary::DelEntry(d1, 10);
#endif

#ifdef TEST_UPDENTRY_07
        Dictionary::Entry newEntry = { 6, "Гурин" };
        Dictionary::UpdEntry(d1, 9, newEntry);
#endif

#ifdef TEST_UPDENTRY_08
        Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
        Dictionary::Entry s1 = { 1, "Иванов" };
        Dictionary::Entry s2 = { 2, "Петров" };
        Dictionary::Entry s3 = { 3, "Сидоров" };
        Dictionary::Entry s4 = { 2, "Яцко" };
        Dictionary::AddEntry(d2, s1);
        Dictionary::AddEntry(d2, s2);
        Dictionary::AddEntry(d2, s3);
        Dictionary::UpdEntry(d2, 3, s4);
#endif

#ifdef TEST_DICTIONARY
        Dictionary::Instance d1 = Dictionary::Create("Студенты", 30);
        Dictionary::Instance d2 = Dictionary::Create("Преподаватели", 10);


        Dictionary::Entry
            e1 = { 1, "Ханецкий" },
            e2 = { 2, "Худовец" },
            e3 = { 3, "Иванов" },
            e4 = { 4, "Свириденко" },
            e5 = { 5, "Яцко" },
            e6 = { 6, "Артур" },
            e7 = { 7, "Пирожков" },
            e8 = { 8, "Валентин" };
        Dictionary::AddEntry(d1, e1);
        Dictionary::AddEntry(d1, e2);
        Dictionary::AddEntry(d1, e3);
        Dictionary::AddEntry(d1, e4);
        Dictionary::AddEntry(d1, e5);
        Dictionary::AddEntry(d1, e6);
        Dictionary::AddEntry(d1, e7);
        Dictionary::AddEntry(d1, e8);

        Dictionary::DelEntry(d1, 8);
        Dictionary::GetEntry(d1, 1);

        Dictionary::Entry e9 = { 10, "Силко" };
        Dictionary::UpdEntry(d1, 7, e9);

        Dictionary::Entry
            ep1 = { 1, "Наркевич" },
            ep2 = { 2, "Смелов" },
            ep3 = { 3, "Белодед" },
            ep4 = { 4, "Бернацкий" },
            ep5 = { 5, "Барковский" },
            ep6 = { 6, "Калиновская" },
            ep7 = { 7, "Гринюк" };
        Dictionary::AddEntry(d2, ep1);
        Dictionary::AddEntry(d2, ep2);
        Dictionary::AddEntry(d2, ep3);
        Dictionary::AddEntry(d2, ep4);
        Dictionary::AddEntry(d2, ep5);
        Dictionary::AddEntry(d2, ep6);
        Dictionary::AddEntry(d2, ep7);


        Dictionary::Print(d1);
        Dictionary::Print(d2);

        Dictionary::Delete(d1);
        Dictionary::Delete(d2);


#endif
    }

    catch (const char* e)
    {
        std::cout << e << std::endl;
    };

    system("pause");
    return 0;
}