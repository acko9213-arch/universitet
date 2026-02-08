#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "Russian");
    int k;
    std::cout << "Вы любите спорт? (1-да, 2-нет)" << std::endl;
    std::cin >> k;
    switch (k)
    {
    case 1: {
        std::cout << "Какой вид спорта вы предпочитаете? (1-волейбол, 2-баскетбол, 3-футбол)" << std::endl;
        std::cin >> k;
        switch (k)
        {
        case 1: std::cout << "Отличный выбор!"; break;
        case 2: std::cout << "Этот спорт требует хороших навыков!"; break;
        case 3: std::cout << "Неплохо."; break;
        default: std::cout << "Неккоректный ответ"; break;
        }
        break;
    }
    case 2: std::cout << "Жаль."; break;
    default: std::cout << "Неккоректный ответ"; break;

    }
 return 0;
}