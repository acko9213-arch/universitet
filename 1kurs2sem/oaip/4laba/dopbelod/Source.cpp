#include <iostream>

int a = 3;
int kvadrat(int x)
{
    return x * x;
}
int main() {
    int a = 4; 
    setlocale(LC_CTYPE, "rus");
    std::cout << "Квадрат локальной a:" << kvadrat(::a) << std::endl;
    std::cout << "Квадрат глобальной a:" << kvadrat(a) << std::endl;
    std::cout << "Произведение локальной a и глобальной a:" << a*::a << std::endl;



    return 0;
}