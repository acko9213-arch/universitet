#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;


//#define TEST_CREATE_01
//#define TEST_CREATE_02
//#define TEST_ADDENTRY_03
//#define TEST_ADDENTRY_04
#define TEST_GETENTRY_05
//#define TEST_DELENTRY_06
//#define TEST_UPDENTRY_07
//#define TEST_UPDENTRY_08
//#define TEST_DICTIONARY

#define DICTNAMEMAXSIZE   20
#define DICTMAXSIZE       100
#define ENTRYNAMEMAXSIZE  30

#define THROW01  "Create: превышен размер имени словаря"
#define THROW02  "Create: превышен размер максимальной ёмкости словаря"
#define THROW03  "AddEntry: переполнение словаря"
#define THROW04  "AddEntry: дублирование идентификатора"
#define THROW05  "GetEntry: не найден элемент"
#define THROW06  "DelEntry: не найден элемент"
#define THROW07  "UpdEntry: не найден элемент"
#define THROW08  "UpdEntry: дублирование идентификатора"