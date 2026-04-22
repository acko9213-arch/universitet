#include <cstring>
#define DICTNAMEMAXSIZE   20
#define DICTMAXSIZE       100
#define ENTRYNAMEMAXSIZE  30

#define THROW01  "Create: превышен размер имени словар€"
#define THROW02  "Create: превышен размер максимальной Ємкости словар€"
#define THROW03  "AddEntry: переполнение словар€"
#define THROW04  "AddEntry: дублирование идентификатора"
#define THROW05  "GetEntry: не найден элемент"
#define THROW06  "DelEntry: не найден элемент"
#define THROW07  "UpdEntry: не найден элемент"
#define THROW08  "UpdEntry: дублирование идентификатора"
namespace Dictionary //
{
    struct Entry        // элемент словар€
    {
        int id;                          // идентификатор (уникальный)
        char name[ENTRYNAMEMAXSIZE];     // символьна€ информаци€
    };

    struct Instance     // экземпл€р словар€
    {
       const char name[DICTNAMEMAXSIZE];      // наименование словар€
        int maxsize;                     // максимальна€ Ємкость словар€
        int size;                        // текущий размер словар€ < DICTNAMEMAXSIZE
        Entry* dictionary;               // массив элементов словар€
    };

    Instance Create(        // создать словарь
        const char name[DICTNAMEMAXSIZE],  // им€ словар€
       const int size                     // Ємкость словар€ < DICTNAMEMAXSIZE
    );

    void AddEntry(          // добавить элемент словар€
        Instance& inst,              // экземпл€р словар€
        Entry ed                     // элемент словар€
    );

    void DelEntry(          // удалить элемент словар€
        Instance& inst,              // экземпл€р словар€
        int id                       // идентификатор удал€емого элемента (уникальный)
    );

    void UpdEntry(          // изменить элемент словар€
        Instance& inst,              // экземпл€р словар€
        int id,                      // идентификатор замен€емого элемента
        Entry new_ed                 // новый элемент словар€
    );

    Entry GetEntry(         // получить элемент словар€
        Instance inst,               // экземпл€р словар€
        int id                       // идентификатор получаемого элемента
    );

    void Print(Instance d);    // печать словар€
    void Delete(Instance& d);  // удалить словарь
};