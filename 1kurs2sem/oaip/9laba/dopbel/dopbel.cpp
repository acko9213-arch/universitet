#include <iostream>

using namespace std;


struct Address
{
	
	int data;
	Address* next;
	Address* prev;
};
void input(Address* &next, Address* &prev,int data)
{
	Address* p = new Address();
	p->data = data;
	p->next = nullptr;
	p->prev = prev;

	if (prev == nullptr) {
		
		next = p;
	}
	else {
		
		prev->next = p;
	}
	prev = p;

}
void outputList(Address* phead,Address* prev)
{
	Address* t = phead;
		while (t != nullptr) {
			cout << t->data << endl;
			t = t->next;
		}
		t = prev;
		while (t != nullptr) {
			cout << t->data << endl;
			t = t->prev;
		}
	
}
int main()
{
	Address* next = nullptr;
	Address* prev = nullptr;
	input(next, prev, 4);
	input(next, prev, 1);

	input(next, prev, 8);

	input(next, prev, 9);
	outputList(next,prev);
	return 0;
}