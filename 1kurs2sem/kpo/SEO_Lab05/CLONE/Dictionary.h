#include "stdafx.h"

namespace Dictionary
{
    struct Entry
    {
        int id;
        char name[ENTRYNAMEMAXSIZE];
    };

    struct Instance
    {
        const char name[DICTNAMEMAXSIZE];
        int maxsize;
        int size;
        Entry* dictionary;
    };

    Instance Create(const char name[DICTNAMEMAXSIZE], const int size);
    void AddEntry(Instance& inst, Entry ed);
    void DelEntry(Instance& inst, int id);
    void UpdEntry(Instance& inst, int id, Entry new_ed);
    Entry GetEntry(Instance inst, int id);
    void Print(Instance d);
    void Delete(Instance& d);
}