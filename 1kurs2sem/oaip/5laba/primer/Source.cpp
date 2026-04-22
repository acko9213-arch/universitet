#include <iostream> 
using namespace std;
#define SQUARE(x) ((x) * (x)) 

#ifdef _WIN64
#define PI 64
#elif _WIN32
 #define PI 32
#endif
double square(double x)
{
    return x*x;
}
int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << " вадрат числа " <<  ": " << SQUARE(PI) << endl; 
    cout << " вадрат числа " << ": " << square(PI) << endl;

    return 0;
}