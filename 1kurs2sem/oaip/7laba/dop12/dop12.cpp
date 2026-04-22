
#include <iostream>
struct valid
{
    int a;
    int b;
    char arr[10];
        bool da;
        
}valid1;
int main()
{
    valid1.arr[2] = '1';
    std::cout << valid1.arr[2];
    return 0;
}


