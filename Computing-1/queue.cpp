#include <iostream>

using namespace std;

class Node {
	public:
		double data; // data
		Node* next; // pointer to next
};
	
class Queue 
{
	public:
		Queue();// constructor
		~Queue();// destructor
		bool IsEmpty(void);
		void Enqueue(double x);
		bool Dequeue(double &x);
		void DisplayQueue(void);
	private:
		Node* front;// front index
		Node* rear;// rear index
		int counter;// number of elements
};

Queue::Queue() 
{
	front = rear = NULL;
	counter = 0;
}

Queue::~Queue() 
{ 
	double value;
	while (!IsEmpty())
		Dequeue(value);
}

bool Queue::IsEmpty() 
{
	if (counter)
		return false;
	else 
		return true;
}

void Queue::Enqueue(double x) 
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	if (IsEmpty()) 
	{
		front = newNode;
		rear = newNode;
	}
	else 
	{
		rear->next = newNode;
		rear = newNode;
	}
	counter++;
}

bool Queue::Dequeue(double &x) 
{
	if (IsEmpty()) 
	{
		cout<< "Error: the queue is empty." << endl;
		return false;
	}
	else 
	{
		x= front->data;
		Node* nextNode = front->next;
		delete front;
		front = nextNode;
		counter--;
	}
}

void Queue::DisplayQueue()
{
	cout<< "front -->";
	Node* currNode = front;
	for (int i = 0; i < counter; i++) 
	{
		if (i == 0) 
			cout << "\t";
		else 
			cout << "\t\t"; 
		cout << currNode->data;
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<--rear" << endl;
		currNode=currNode->next;
	}
}

int main(void) 
{
	Queue queue;
	cout<< "Enqueue 5 items." << endl;
	for (int x = 0; x < 5; x++)
		queue.Enqueue(x);
	cout<< "Now attempting to enqueue again..." << endl;
	queue.Enqueue(5);
	queue.DisplayQueue();
	double value;
	queue.Dequeue(value);
	cout<< "Retrieved element = " << value << endl;
	queue.DisplayQueue();
	queue.Enqueue(7);
	queue.DisplayQueue();
	return 0;
}