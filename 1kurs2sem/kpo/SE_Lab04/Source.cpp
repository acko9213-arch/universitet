#include <iostream>

using namespace std;
typedef unsigned short day;    
typedef unsigned short month;  
typedef unsigned short year;  

struct Date 
{
    day   dd;
    month mm;
    year  yyyy;
    bool operator==(const Date& date) 
    {
            return dd == date.dd && mm == date.mm && yyyy == date.yyyy;
    }
    bool operator<(const Date& date) const
    {
       return yyyy < date.yyyy || yyyy == date.yyyy && (mm < date.mm || mm == date.mm && dd < date.dd);
    }
    bool operator>(const Date& date) 
    {

        return date <*this;
    }
};
int main()
{
    setlocale(LC_ALL, "rus");

    Date date1 = { 7, 1, 1980 };
    Date date2 = { 7, 2, 1993 };
    Date date3 = { 7, 1, 1980 };
    if (date1 < date2)
    {
        cout << "истина" <<endl;
    }
    else
    {
        cout << "ложь" << endl;
    }

    if (date1 > date2)
    {
        cout << "истина" << endl;
    }
    else               cout << "ложь" << endl;

    if (date1 == date2) cout << "истина" << endl;
    else                cout << "ложь" << endl;

    if (date1 == date3) cout << "истина" << endl;
    else                cout << "ложь" <<endl;

	return 0;
}