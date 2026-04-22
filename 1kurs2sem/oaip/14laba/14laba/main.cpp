#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (int i = 0; i < 5; i++)
	{
		AAA* a = new AAA;
		a->x = i * 10; 
		h2.insert(a);
	}
    for (;;)
    {
        cout << "\n1 - Вывод кучи h1 на экран\n";
        cout << "2 - Добавить элемент в h1\n";
        cout << "3 - Удалить максимальный элемент (extractMax)\n";
        cout << "4 - Удалить элемент по индексу (delall)\n";
        cout << "5 - Удалить минимальный элемент (delmin)\n";
        cout << "6 - Сложить две кучи (переместить h2 в h1)\n";
        cout << "0 - Выход\n";
        cout << "Сделайте выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            h1.scan(0);
            break;

        case 2:
            cout << "Введите ключ: ";
            cin >> k;
            {
                AAA* a = new AAA{ k };
                h1.insert(a);
            }
            break;

        case 3:
            h1.extractMax();
            cout << "Максимальный элемент удалён\n";
            break;

        case 4:
            cout << "Введите индекс для удаления: ";
            cin >> k;
            h1.delall(k);
            break;

        case 5:
            h1.delmin();
            cout << "Минимальный элемент удалён\n";
            break;

        case 6:
            h1.add(&h2);        
            cout << "h2 добавлена в h1 (h2 теперь пустая)\n";
            break;
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}