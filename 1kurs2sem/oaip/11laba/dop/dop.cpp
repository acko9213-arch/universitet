#include <iostream>
using namespace std;
struct Deque {
    Deque* next;
    int count;
};
struct List {
	int data;
	List* next;
};
Deque* head = nullptr;
Deque* tail = nullptr;
void input(List*& head, int value)
{
	List* p = new List;
	p->data = value;
	p->next = head;
	head = p;

}
void output(List* head)
{
	List* current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl << "Список выведен." << endl;
}



void push_back(int value) {
    Deque* newNode = new Deque;   
    newNode->count = value;       
    newNode->next = nullptr;

    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

 
void pop_front() {
    if (head==nullptr) {
        cout << "Дек пуст! Нечего удалять.\n";
        return;
    }

    Deque* temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    
}

void pop_back() {
    if (tail==nullptr) {
        cout << "Дек пуст! Нечего удалять.\n";
        return;
    }

    if (head == tail) {  
        delete head;
        head = tail = nullptr;
    }
    else {
        
        Deque* current = head;
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    }
   
}


int front() {
    if (head==nullptr) {
        cout << "Дек пуст!\n";
        return -1;
    }
    return head->count;
}


int back() {
    if (tail == nullptr) {
        cout << "Дек пуст!\n";
        return -1;
    }
    return tail->count;
}
int main()
{
	List* head1 = nullptr;
	List* head2 = nullptr;

	int value;
	setlocale(LC_CTYPE, "RUS");
    push_back(1);
    push_back(2);

    push_back(3);
    push_back(4);
    push_back(5);
    push_back(6);
    push_back(7);
    push_back(8);


	while(head)
	{
		input(head1,front());		input(head2, back());

        pop_back();
            pop_front();
	}
	output(head1);
	output(head2);


	return 0;
}