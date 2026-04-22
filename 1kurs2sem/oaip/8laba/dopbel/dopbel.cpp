#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void pushFront(Node*& head, int value) {
    Node* newel = new Node{ value, head };
   
    head = newel; 
    
}
int main()
{
    setlocale(LC_CTYPE, "RUS");
    Node* head = nullptr;
    pushFront(head, 0);
    pushFront(head, 1);
    pushFront(head, 2);
    pushFront(head, 7);
    int arr[100];
    int i = 0;
    while (head!=nullptr)
    {
        arr[i] = head->data;

        head = head->next;
        i++;
    }
    cout << "Ваш пинкод:";
    i--;
    for (i; i >=0; i--)
    {
        cout << arr[i];
    }
    return 0;
}