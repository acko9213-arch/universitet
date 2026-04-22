#include <iostream>
#include <deque>
using namespace std;
struct List {
	int data;
	List* next;
};
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
int main()
{
	List* head1 = nullptr;
	List* head2 = nullptr;

	deque <int> deq;
	int value;
	setlocale(LC_CTYPE, "RUS");
	deq.push_back(1);
	deq.push_back(4);

	deq.push_back(5);

	deq.push_back(6);
	deq.push_back(7);
	deq.push_back(8);
	deq.push_back(9);
	deq.push_back(10);
	while (!deq.empty())
	{
		input(head1, deq.front());		input(head2, deq.back());

		deq.pop_front();
		deq.pop_back();
	}
	output(head1);
	output(head2);


	return 0;
}