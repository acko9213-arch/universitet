#include "Dictionary.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

namespace Dictionary {

    Instance Create(const char* name, const int size)
    {
        if (strlen(name) > DICTNAMEMAXSIZE)
            throw THROW01;
        if (DICTMAXSIZE < size || size <= 0)
            throw THROW02;

        Entry* arr1 = new Entry[size];
        for (int i = 0; i < size; i++) {
            arr1[i].id = 0;
            arr1[i].name[0] = '\0';
        }
        Instance SLOVAR = { "", size, 0, arr1 };
        strcpy_s(SLOVAR.name, DICTNAMEMAXSIZE, name);
        return SLOVAR;
    }

    void AddEntry(Instance& inst, Entry ed)
    {
        if (inst.size >= inst.maxsize) throw THROW03;
        for (int i = 0; i < inst.size; i++)
            if (inst.dictionary[i].id == ed.id)
                throw THROW04;

        inst.dictionary[inst.size].id = ed.id;
        strcpy_s(inst.dictionary[inst.size].name, ENTRYNAMEMAXSIZE, ed.name);
        inst.size++;
    }

    void DelEntry(Instance& inst, int id)
    {
        if (id <= 0 || inst.size < id)
            throw THROW06;
        for (int i = id - 1; i < inst.size - 1; i++)
            inst.dictionary[i] = inst.dictionary[i + 1];
        inst.size--;
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed)
    {
        int pos = -1;
        for (int i = 0; i < inst.size; i++)
            if (inst.dictionary[i].id == id) { pos = i; break; }

        if (pos == -1) throw THROW07;

        for (int i = 0; i < inst.size; i++)
            if (i != pos && inst.dictionary[i].id == new_ed.id)
                throw THROW08;

        inst.dictionary[pos].id = new_ed.id;
        strcpy_s(inst.dictionary[pos].name, ENTRYNAMEMAXSIZE, new_ed.name);
    }

    Entry GetEntry(Instance inst, int id)
    {
        for (int i = 0; i < inst.size; i++)
            if (inst.dictionary[i].id == id)
                return inst.dictionary[i];
        throw THROW05;
    }

    void Print(Instance d)
    {
        cout << "---------- " << d.name << " ----------" << endl;
        for (int i = 0; i < d.size; i++)
            cout << i + 1 << " " << d.dictionary[i].name << endl;
    }

    void Delete(Instance& d)
    {
        delete[] d.dictionary;
        d.dictionary = nullptr;
        d.size = 0;
    }
}