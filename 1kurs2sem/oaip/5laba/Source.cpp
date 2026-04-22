#include <iostream> 
using namespace std;
static int i = 0;
static int sum = 0;
static int sum1 = 0;
typedef int kgramm; 
typedef int gramm; 
void vichesl(int arr1[], int arr2[],int k,int n)
{
    
    kgramm g;
    gramm f;
   
    cout << "Введите количество килограмм:";
    cin >> g;
    arr1[i] = g;
    cout << "Введите количество грамм:";
    cin >> f;
    arr2[i] = f;
 
        sum1 += arr2[i];
    
    sum+= arr1[i] + ((int)(sum1 / 1000));
    i++;
   
  
    sum1=sum1 - (sum1 / 1000)*1000;
   
    cout << "Общее количество кг:" << sum << endl;
    int q;
    cout << "Продолжить считать кг?(1 - ДА,2 - НЕТ)" << endl;
    cin >> q;
    switch (q)
    {
    case 1:vichesl(arr1, arr2, k, n); break;
    case 2: cout << "Программа закончена."; break;
    default:  cout << "Вы ввели не то число."; break;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
   static int n;
   static int k;
    cout << "Введите размер массива A:";
    cin >> n;
    cout << "Введите размер массива B:";
    cin >> k;
    int* arr1 = new int[k];
    int* arr2 = new int[n];
    vichesl(arr1, arr2,k,n);
    delete[] arr1;
    delete[] arr2;
    return 0; 
}