#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.cpp"
using std::cout;
using std::cin;

int main() 
{
	int numitems; // Added to get the length of list.
	CList<int> newlist1;
	CList<double> newlist2;
	cout << "Newly built (and thus empty) CLists should not accept pop- functions!\n";
	cout << "Test popback for empty integer and double lists:\n";
	cout << "Integer List: ";
	newlist1.popback();
	cout << "Double List: ";
	newlist2.popback();
	cout << "Test popfront for empty integer and double lists:\n";
	cout << "Integer List: ";
	newlist1.popfront();
	cout << "Double List: ";
	newlist2.popfront();
	cout << "Empty tests passed.\n\n";
	
	cout << "The original integer list is: ";
	for (int i=1;i<4;i++) {
		newlist1.pushback(i);
		cout << i << " ";
	}
	cout << "\n";
	cout << "The original double list is: ";
	for (double i=1.46;i<1.54;i+=0.02) {
		newlist2.pushback(i);
		cout << i << " ";
	}
	cout << "\n(This part of initialization is also done by pushback.)\n" << "\n";
	
	
	cout << "Test cases for pushback:\n";
    cout << "Do pushback for newlist1 (push 7 here):\n";
    newlist1.pushback(7); // Do pushback.
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "Pushed newlist1: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do pushback for newlist2 (push 1.7 here):\n";
    newlist2.pushback(1.7); // Do pushback.
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "Pushed newlist2: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n" << "\n";
	
	
	cout << "Test cases for pushfront:\n";
    cout << "Do pushfront for newlist1 (push 5 here):\n";
    newlist1.pushfront(5); // Do pushfront.
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "Pushed newlist1: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do pushfront for newlist2 (push 6.4 here):\n";
    newlist2.pushfront(6.4); // Do pushfront.
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "Pushed newlist2: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n" << "\n";
	
	
	cout << "Test cases for popback:\n";
    cout << "Do popback for newlist1 (should pop 7):\n";
    int pop_int;
    pop_int=newlist1.popback(); // Do popback.
    cout << "The poped value is: " << pop_int << "\n";
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "Poped newlist1: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do popback for newlist2 (should pop 1.7):\n";
	double pop_double;
	pop_double=newlist2.popback(); // Do popback.
	cout << "The poped value is: " << pop_double << "\n";
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "Poped newlist2: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n" << "\n";
	
	
	cout << "Test cases for popfront:\n";
    cout << "Do popfront for newlist1 (should pop 5):\n";
    int pop_int0;
    pop_int0=newlist1.popfront(); // Do popfront.
    cout << "The poped value is: " << pop_int0 << "\n";
	numitems = newlist1.getlength(); // Get the length of the new list.
	cout << "Poped newlist1: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist1[i] << " ";
	}
	cout << "\n";
	cout << "Do popfront for newlist2 (should pop 6.4):\n";
	double pop_double0;
	pop_double0=newlist2.popfront(); // Do popfront.
	cout << "The poped value is: " << pop_double0 << "\n";
	numitems = newlist2.getlength(); // Get the length of the new list.
	cout << "Poped newlist2: ";
	for (int i=1; i<=numitems; i++) {
		cout << newlist2[i] << " ";
	}
	cout << "\n";
	
	
	return 0;

}
