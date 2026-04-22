#include <iostream>

#include <string>
using namespace std;
typedef string name;
typedef int ploshad;
typedef int nacelenie;
typedef string valut;

struct Country
{
    name im;
    ploshad pl;
    nacelenie nac;
    valut val;
    bool operator==(const Country& date)
    {
        return im == date.im && pl == date.pl && nac == date.nac && val == date.val;
    }
    bool operator>(const Country& date) 
    {

        if (pl!= date.pl)
        {
            return pl > date.pl;
        }
       
        return nac > date.nac;
    }
    double plotnost(Country date)
    {
        return (double)nac / pl;
    }

    
    bool operator<(const Country& date)
    {
        return plotnost(*this) < plotnost(date);
    }
};
int main()
{
    setlocale(LC_ALL, "rus");
    Country c1 = { "Китай",15000000,1500000000,"юань" };
    Country c2 = { "Россия",17000000,140000000,"российский рубль" };
    Country c3 = { "Беларусь",230000,9000000,"белорусский рубль" };
    Country c4 = { "Япония",5000000,120000000,"йена" };
    Country c5 = { "Китай",15000000,1500000000,"юань" };
    if (c1 < c2)
    {
        cout << "Плотность c2 больше c1";

    }
    else
    {
        cout << "Плотность c1 больше c2";
    }
    cout << endl;
    if (c1 == c5)
    {
        cout << "Истина" ;
    }
    else
    {
        cout << "Ложь";
    }
    cout << endl;
    if (c1 == c3)
    {
        cout << "Истина";
    }
    else
    {
        cout << "Ложь";
    }
    cout << endl;
    if (c1>c2)
    {
        cout << "Население и площадь 1 страны больше населения и площади 2 страны";
    }
    else
    {
        cout << "Население или площадь 1 страны меньше населения или площади 2 страны";
    }
    cout << endl;
    if (c1 > c4)
    {
        cout << "Население и площадь 1 страны больше населения и площади 4 страны";
    }
    else
    {
        cout << "Население или площадь 1 страны меньше населения или площади 4 страны";
    }
   
  
    return 0;
}
